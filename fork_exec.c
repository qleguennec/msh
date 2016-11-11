/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 20:58:27 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/11 01:33:21 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"
#include "libprintf/libprintf.h"
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

static int	child_exec(t_dict *env, char *name, char **cmd)
{
	char	**env_exp;
	int		ret;

	env_exp = dict_str_export(env, "=");
	ret = execve(name, cmd, env_exp);
	free(env_exp);
	return (ret == -1);
}

int			is_exec(char *name)
{
	struct stat		st;

	if (stat(name, &st) == -1)
		return (0);
	if (access(name, X_OK) == -1)
	{
		WARN(g_warn_deny, name);
		return (0);
	}
	return (1);
}

int			fork_exec(t_dict *env, char *name, char **cmd, int *status)
{
	int		ret;
	pid_t	child;

	if (!is_exec(name))
		return (0);
	ret = 0;
	if ((child = fork()) == -1)
	{
		WARN(g_warn_fork, child);
		return (0);
	}
	if (!child)
		ret = child_exec(env, name, cmd);
	else
	{
		waitpid(child, status, 0);
		if (ret)
		{
			WARN(g_warn_exec, 0);
			return (0);
		}
		return (1);
	}
	return (1);
}
