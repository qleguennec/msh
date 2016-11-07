/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 20:58:27 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/07 23:29:25 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"
#include "malloc.h"
#include "libft/libft.h"
#include "libgnl/libgnl.h"
#include "libprintf/libprintf.h"
#include <dirent.h>
#include <unistd.h>
#include <sys/wait.h>

static int		exec(char *name, char **cmd, char **env)
{
	pid_t		child;
	int			ret;
	int			status;

	if ((child = fork()) < 0)
	{
		WARN(g_warn_fork, child);
		return (ERR_FORK);
	}
	else if (!child)
		ret = execve(name, cmd, env);
	else
	{
		waitpid(child, &status, 0);
		return (status);
	}
	return (ret);
}

static int		run_path(char **cmd, char **path, char **env)
{
	DIR				*dir;
	char			*name;
	struct dirent	*ent;
	int				ret;

	while (*path)
	{
		if (!(dir = opendir(*path++)))
			continue ;
		while ((ent = readdir(dir)))
		{
			if (!strcmp(cmd[0], ent->d_name))
			{
				name = path_concat(*path, *cmd);
				ret = exec(name, cmd, env);
				free(name);
				closedir(dir);
				return (ret);
			}
		}
		closedir(dir);
		path++;
	}
	return (-1);
}

static int		run(char **cmd, char **path, char **env)
{
	int				ret;

	if ((ret = exec(*cmd, cmd, env)) > 0)
		return (ret);
	if ((ret = run_path(cmd, path, env)) > 0)
		return (ret);
	WARN(g_warn_notf, *cmd);
	return (127);
}

static int		loop(char **env, char **env_end, char **path)
{
	int			gnl_ret;
	int			run_ret;
	char		**cmd;

	BZERO(t_vect, buf);
	BZERO(t_vect, line);
	(void)env_end;
	while (42)
	{
		msh_prompt();
		if ((gnl_ret = get_next_line(0, &buf, &line)) == -1)
			msh_exit(g_read_err);
		if (!gnl_ret)
			break ;
		cmd = nsplit(line.data, line.used, &ft_isspace);
		run_ret = run(cmd, path, env);
		arr_free((void **)cmd);
		line.used = 0;
		ft_printf("%d ", run_ret);
	}
	return (0);
}

int				main(int argc, char **argv, char **environ)
{
	char		**env_end;
	char		**path;
	char		ans[QUERY_BUFSIZ];

	(void)argc;
	(void)argv;
	env_end = environ;
	while (*environ && *(env_end + 1))
		env_end++;
	ft_qsort((void **)environ, env_end - environ, &env_cmp, 0);
	path = nsplit(ans, msh_env_query(ans, "PATH", environ, env_end), &iscolon);
	loop(environ, env_end, path);
	arr_free((void **)path);
	return (0);
}
