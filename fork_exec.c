/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 20:58:27 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/14 13:44:57 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"
#include "libprintf/libprintf.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

static int	exec_isx(char *name)
{
	struct stat		st;

	if (stat(name, &st) == -1)
		return (0);
	if (access(name, X_OK) == -1)
	{
		WARN(W_DENY, name);
		return (0);
	}
	return (1);
}

int			fork_exec(char **env_exp, char *name, char **cmd)
{
	if (!exec_isx(name))
		return (0);
	g_child = fork();
	if (!g_child)
	{
		if (execve(name, cmd, env_exp) == -1)
			return (0);
	}
	return (1);
}
