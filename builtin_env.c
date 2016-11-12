/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 02:42:21 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/12 01:57:23 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"
#include "libprintf/libprintf.h"

static void	env_unset(t_dict *env, char *key)
{
	t_dict_ent	*ent;

	ent = dict_lookup(env, key);
	if (!ent)
		return ;
	dict_ent_del(env, ent);
}

static int	env_run(t_dict *env, char **cmd)
{
	int		status;
	int		ret;

	ret = 0;
	if (!*cmd)
		dict_print(env, "=", "\n");
	else if (!msh_exec(env, cmd, &status))
	{
		WARN(g_warn_notf, *cmd);
		ret = 1;
	}
	dict_free(env);
	return (ret);
}

int			builtin_env(t_dict *env, char **cmd)
{
	t_dict	new;

	dict_str_init(&new, env->total);
	dict_dup(env, &new);
	while (*++cmd)
	{
		if (*cmd[0] != '-')
			break ;
		if (!ft_strcmp(*cmd, "-i"))
			dict_clear(&new);
		if (!ft_strcmp(*cmd, "-u"))
		{
			if (!*++cmd)
			{
				WARN(g_warn_binoarg, "-u");
				return (1);
			}
			else
				env_unset(&new, *cmd);
		}
	}
	while (*cmd && dict_str_import(&new, *cmd, "="))
		cmd++;
	return (env_run(&new, cmd));
}
