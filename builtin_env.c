/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 02:42:21 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/14 15:24:58 by qle-guen         ###   ########.fr       */
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
		WARN(W_NOTF, *cmd);
		return (0);
	}
	return (1);
}

static int	env_opt_unset(t_dict *env, char ***cmd)
{
	int		i;

	i = 0;
	while (**cmd
		&& (!i || (*cmd)[1])
		&& ***cmd != '-'
		&& !ft_strstr(**cmd, "="))
	{
		dict_del(env, **cmd);
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

static int	env_opt(t_dict *env, char ***cmd)
{
	if ((**cmd)[1] == 'i')
	{
		(*cmd)++;
		dict_clear(env);
		return (1);
	}
	else if ((**cmd)[1] == 'u')
	{
		(*cmd)++;
		return (env_opt_unset(env, cmd));
	}
	WARN(W_NOOPT, (**cmd)[1]);
	return (0);
}

static int	env_run(t_dict *env, char **cmd)
{
	while (*cmd && **cmd == '-')
	{
		if (!env_opt(env, &cmd))
			return (1);
	}
	while (*cmd && dict_str_import(env, *cmd, "=", &dict_str_set))
		cmd++;
	return (!env_exec(env, cmd));
}

int			builtin_env(t_dict *env, char **cmd)
{
	return ((int)dict_fmap(env
		, DICT_USED
		, (void *(*)(t_dict *, void *))&env_run
		, (void *)(cmd + 1)));
}
