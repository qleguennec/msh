/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@studhome.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 01:37:05 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/25 16:45:11 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"
#include "libprintf/libprintf.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

static char		*get_arg(char **cmd)
{
	t_dict_ent	*home;

	if (cmd[1])
		return (cmd[1]);
	else
	{
		WLOOKUP(home, "HOME");
		if (!home)
			return (NULL);
		return (home->val.data);
	}
}

static int		set_pwd(void)
{
	char	buf[1024];

	if (getcwd(buf, sizeof(buf)) == NULL)
	{
		WARN(W_OOB, 0);
		return (1);
	}
	SET("PWD", buf);
	return (0);
}

int				builtin_cd(char **cmd)
{
	char			*name;
	struct stat		st;

	if (!(name = get_arg(cmd)))
		return (1);
	if (stat(name, &st) == -1)
	{
		WARN(W_NOTF, name);
		return (1);
	}
	if (access(name, X_OK) == -1)
	{
		WARN(W_DENY, name);
		return (1);
	}
	if (chdir(name) == -1)
	{
		WARN(W_CHDIR, 0);
		return (1);
	}
	return (set_pwd());
}
