/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 02:42:21 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/11 04:00:22 by qle-guen         ###   ########.fr       */
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
	char	**env_exp;
	char	*name;
	int		status;

	if (!*cmd)
	{
		env_exp = dict_str_export(env, "=");
		while (*env_exp)
			ft_printf("%s\n", env_exp++);
		ft_arr_free((void **)env_exp);
		return (0);
	}
	if (fork_exec(env, *cmd, cmd, &status))
		return (status);
	name = get_cmd_path(env, *cmd);
	if (name && fork_exec(env, name, cmd, &status))
		return (status);
	free(name);
	WARN(g_warn_notf, *cmd);
	return (0);
}

int			builtin_env(t_dict *env, char **cmd)
{
	t_dict	new;

	dict_str_init(&new, env->used * DICT_GROWTH_FACTOR);
	dict_dup(&new, env);
	while (++*cmd)
	{
		if (*cmd[0] != '-')
			break ;
		if (!ft_strcmp(*cmd, "-i"))
			dict_del(&new);
		if (!ft_strcmp(*cmd, "-u"))
		{
			if (!++*cmd)
				WARN(g_warn_binoarg, "env", "-u");
			else
				env_unset(&new, *cmd);
		}
	}
	while (*cmd && dict_str_import(&new, *cmd, "="))
		cmd++;
	return (env_run(&new, cmd));
}
