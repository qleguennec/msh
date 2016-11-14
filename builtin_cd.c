/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@studhome.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 01:37:05 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/14 16:12:30 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"
#include "libprintf/libprintf.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

char	*cd_get_arg(t_dict *env, char **cmd)
{
	t_dict_ent	*home;
	t_dict_ent	*oldpwd;

	if (!cmd[1])
	{
		if (!(home = dict_lookup(env, "HOME")))
		{
			WARN(W_NOENV, "HOME");
			return (NULL);
		}
		return (home->val.data);
	}
	if (*cmd[1] == '-')
	{
		if (!(oldpwd = dict_lookup(env, "OLDPWD")))
		{
			WARN(W_NOENV, "OLDPWD");
			return (NULL);
		}
		free(cmd[1]);
		cmd[1] = ft_strdup(oldpwd->val.data);
	}
	return (cmd[1]);
}

int		cd_set_pwd(t_dict *env)
{
	char		buf[1024];
	t_dict_ent	*pwd;

	if (getcwd(buf, sizeof(buf)) == NULL)
	{
		WARN(W_OOB, 0);
		return (1);
	}
	if (!(pwd = dict_lookup(env, "PWD")))
	{
		dict_str_add(env, "PWD", buf);
		return (0);
	}
	dict_str_set(env, "OLDPWD", pwd->val.data);
	dict_str_set(env, "PWD", buf);
	return (0);
}

int		builtin_cd(t_dict *env, char **cmd)
{
	char		*name;
	struct stat	st;

	if (!(name = cd_get_arg(env, cmd)))
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
	return (cd_set_pwd(env));
}
