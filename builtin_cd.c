/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@studhome.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 01:37:05 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/13 19:47:55 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"
#include "libprintf/libprintf.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

char	*cd_hyphen_expand(t_dict *env, char *cmd)
{
	size_t		len;
	t_dict_ent	*oldpwd;
	t_vect		cmd_new;

	oldpwd = dict_lookup(env, "OLDPWD");
	if (!oldpwd)
		return (NULL);
	len = ft_strlen(cmd);
	BZERO(cmd_new);
	vect_add(&cmd_new, oldpwd->val.data, oldpwd->val.used - 1);
	vect_add(&cmd_new, cmd + 1, len);
	return (cmd_new.data);
}

char	*cd_get_arg(t_dict *env, char **cmd)
{
	t_dict_ent	*home;
	char		*buf;

	if (!cmd[1])
	{
		if (!(home = dict_lookup(env, "HOME")))
		{
			WARN(g_warn_noenv, "HOME");
			return (NULL);
		}
		return (home->val.data);
	}
	if (*cmd[1] == '-')
	{
		buf = cd_hyphen_expand(env, cmd[1]);
		free(cmd[1]);
		cmd[1] = buf;
	}
	return (cmd[1]);
}

int		cd_set_pwd(t_dict *env)
{
	char		buf[1024];
	t_dict_ent	*pwd;

	if (getcwd(buf, sizeof(buf)) == NULL)
	{
		WARN(g_warn_oob, 0);
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
		WARN(g_warn_notf, name);
		return (1);
	}
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
	return (cd_set_pwd(env));
}
