/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 20:58:27 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/14 16:09:18 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"
#include "libft/malloc.h"
#include "libft/libft.h"
#include "libgnl/libgnl.h"
#include "libprintf/libprintf.h"
#include <dirent.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

static int		builtin_exec(t_dict *env, char **cmd, int *status)
{
	int			(*b)(t_dict *, char **);

	b = NULL;
	if (!b && !ft_strcmp(*cmd, "cd"))
		b = &builtin_cd;
	if (!b && !ft_strcmp(*cmd, "echo"))
		b = &builtin_echo;
	if (!b && !ft_strcmp(*cmd, "env"))
		b = &builtin_env;
	if (!b && !ft_strcmp(*cmd, "dict"))
		b = &builtin_dict;
	if (!b && !ft_strcmp(*cmd, "setenv"))
		b = &builtin_setenv;
	if (!b && !ft_strcmp(*cmd, "unsetenv"))
		b = &builtin_unsetenv;
	if (!b && !ft_strcmp(*cmd, "clearenv"))
		b = &builtin_clearenv;
	if (!b)
		return (0);
	*status = b(env, cmd);
	return (1);
}

static int		loop_exit(char **cmd)
{
	int			ret;
	size_t		i;

	if (!*cmd[1])
		return (2);
	i = -1;
	while (cmd[1][++i])
	{
		if (!ft_isdigit(cmd[1][i]))
		{
			WARN(W_NUMARG, cmd[1]);
			return (255);
		}
	}
	ret = ft_atoi(cmd[1]);
	ft_arr_free((void **)cmd);
	return (ret);
}

static int		run(t_dict *env, char **cmd, int *status)
{
	if (!ft_strcmp(*cmd, "exit"))
		return (-1);
	if (builtin_exec(env, cmd, status))
		return (1);
	if (msh_exec(env, cmd, status))
		return (1);
	WARN(W_NOTF, *cmd);
	return (0);
}

static int		loop(t_dict *env, t_vect *buf, t_vect *line)
{
	int			gnl_ret;
	int			run_ret;
	int			status;
	char		**cmd;

	while (42)
	{
		msh_prompt(env);
		if ((gnl_ret = get_next_line(0, buf, line)) == -1)
			msh_exit(W_IO);
		if (!gnl_ret)
			break ;
		if (!line->used)
			continue ;
		if (*(cmd = msh_read(env, line)))
		{
			if ((run_ret = run(env, cmd, &status)) == -1)
				return (loop_exit(cmd));
			else
				msh_status(env, run_ret, status);
		}
		ft_arr_free((void **)cmd);
		line->used = 0;
	}
	return (0);
}

int				main(int argc, char **argv, char **environ)
{
	t_dict		env;
	t_vect		buf;
	t_vect		line;
	int			ret;

	(void)argc;
	(void)argv;
	dict_str_init(&env, 16);
	while (*environ)
		dict_str_import(&env, *environ++, "=", &dict_str_add);
	BZERO(buf);
	BZERO(line);
	signal(SIGINT, &sighandle_int);
	ret = loop(&env, &buf, &line);
	free(buf.data);
	free(line.data);
	dict_free(&env);
	return (ret);
}
