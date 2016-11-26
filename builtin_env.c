/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 02:42:21 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/25 16:01:05 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"
#include "libprintf/libprintf.h"
#include <unistd.h>

static int	env_exec(char **cmd)
{
	int		status;

	if (!*cmd)
		dict_print(&g_env, "=", "\n");
	else if (!msh_exec(cmd, &status))
	{
		WARN(W_NOTF, *cmd);
		return (0);
	}
	return (1);
}

static int	env_opt_unset(char ***cmd)
{
	int		i;

	i = 0;
	while (**cmd
		&& (!i || (*cmd)[1])
		&& ***cmd != '-'
		&& !ft_strstr(**cmd, "="))
	{
		DELETE(**cmd);
		(*cmd)++;
		i++;
	}
	if (!i)
	{
		WARN(W_BIARG, "-u");
		return (0);
	}
	return (1);
}

static int	env_opt(char ***cmd)
{
	if ((**cmd)[1] == 'i')
	{
		(*cmd)++;
		dict_clear(&g_env);
		return (1);
	}
	else if ((**cmd)[1] == 'u')
	{
		(*cmd)++;
		return (env_opt_unset(cmd));
	}
	WARN(W_NOOPT, (**cmd)[1]);
	return (0);
}

static int	env_run(char **cmd)
{
	while (*cmd && **cmd == '-')
	{
		if (!env_opt(&cmd))
			return (1);
	}
	while (*cmd && IMPORT(*cmd))
		cmd++;
	return (!env_exec(cmd));
}

int			builtin_env(char **cmd)
{
	int		child;
	int		status;

	cmd++;
	status = 0;
	child = fork();
	if (!child)
		exit(env_run(cmd));
	else
		wait(&status);
	return (status);
}
