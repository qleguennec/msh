/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@studhome.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 01:37:05 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/11 21:03:18 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"
#include "libprintf/libprintf.h"
#include <unistd.h>

char	*get_arg(t_dict *env, char **cmd)
{
	t_dict_ent	*home;

	if (cmd[1])
		return (cmd[1]);
	else
	{
		if (!(home = dict_lookup(env, "HOME")))
		{
			WARN(g_warn_noenv, "HOME");
			return (NULL);
		}
		return (home->val.data);
	}
}

int		builtin_cd(t_dict *env, char **cmd)
{
	char		*name;

	if (!(name = get_arg(env, cmd)))
		return (1);
	if (access(name, X_OK) == -1)
	{
		WARN(g_warn_deny, name);
		return (1);
	}
	if (chdir(name) == -1)
	{
		WARN(g_warn_chdir, 0);
		return (1);
	}
	dict_str_set(env, "PWD", name);
	return (0);
}
