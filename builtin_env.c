/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 02:42:21 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/12 19:36:16 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"
#include "libprintf/libprintf.h"

static int	env_exec(t_dict *env, char **cmd)
{
	int		status;

	if (!*cmd)
		dict_print(env, "=", "\n");
	else if (!msh_exec(env, cmd, &status))
	{
		WARN(g_warn_notf, *cmd);
		return (0);
	}
	return (1);
}

static int	env_opt(t_dict *env, char ***cmd)
{
	int		i;

	if ((**cmd)[1] == 'i')
	{
		(*cmd)++;
		dict_clear(env);
		return (1);
	}
	else if ((**cmd)[1] == 'u')
	{
		(*cmd)++;
		i = 0;
		while (**cmd && ***cmd != '-' && !ft_strstr(**cmd, "=") && ++i)
		{
			dict_del(env, **cmd);
			(*cmd)++;
		}
		if (!i)
		{
			WARN(g_warn_binoarg, "-u");
			return (0);
		}
		return (1);
	}
	(*cmd)++;
	return (1);
}

static int	env_run(t_dict *env, char **cmd)
{
	while (*cmd && **cmd == '-')
	{
		if (!env_opt(env, &cmd))
			return (1);
	}
	while (*cmd && dict_str_import(env, *cmd, "="))
		cmd++;
	return (!env_exec(env, cmd));
}

int			builtin_env(t_dict *env, char **cmd)
{
	return ((int)dict_fmap(env
		, DICT_USED
		, (void *(*)(t_dict *, void *))&env_run
		, (void *)(cmd + 1))
	);
}
