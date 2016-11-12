/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 20:58:27 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/12 01:20:12 by qle-guen         ###   ########.fr       */
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

static int		run(t_dict *env, char **cmd, int *status)
{
	if (builtin_exec(env, cmd, status))
		return (1);
	if (msh_exec(env, cmd, status))
		return (1);
	WARN(g_warn_notf, *cmd);
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
			msh_exit(g_read_err);
		if (!gnl_ret)
			break ;
		if (!line->used && write(1, "0 ", 2))
			continue ;
		if (!ft_memcmp(line->data, "exit", 4))
			break ;
		cmd = ft_nsplit(line->data, line->used, &ft_isspace);
		run_ret = run(env, cmd, &status) ? status : STATUS_NOTF;
		ft_arr_free((void **)cmd);
		line->used = 0;
		ft_printf("%d ", run_ret);
	}
	return (0);
}

int				main(int argc, char **argv, char **environ)
{
	t_dict		env;
	t_vect		buf;
	t_vect		line;

	(void)argc;
	(void)argv;
	dict_str_init(&env, 16);
	while (*environ)
		dict_str_import(&env, *environ++, "=");
	BZERO(buf);
	BZERO(line);
	loop(&env, &buf, &line);
	free(buf.data);
	free(line.data);
	dict_free(&env);
	return (0);
}
