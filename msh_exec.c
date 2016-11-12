/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 04:01:47 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/12 01:55:42 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

int		msh_exec(t_dict *env, char **cmd, int *status)
{
	char	*name;
	int		ret;

	ret = 0;
	if (fork_exec(env, *cmd, cmd, status))
		return (1);
	name = get_cmd_path(env, *cmd);
	if (name && fork_exec(env, name, cmd, status))
		ret = 1;
	free(name);
	return (ret);
}
