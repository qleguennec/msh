/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 01:37:05 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/28 23:44:05 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"
#include "libprintf/libprintf.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

static int		set_pwd(void)
{
	char		buf[1024];
	t_dict_ent	*pwd;

	if (getcwd(buf, sizeof(buf)) == NULL)
	{
		WARN(W_OOB, 0);
		return (1);
	}
	pwd = LOOKUP("PWD");
	if (pwd)
		SET("OLDPWD", pwd->val.data);
	SET("PWD", buf);
	return (0);
}

int				builtin_cd(t_vll *cmd)
{
	char			*name;
	struct stat		st;

	name = VLL_DATA(cmd->head->next);
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
