/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 04:01:47 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/25 16:39:14 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"
#include <sys/wait.h>

int		msh_exec(char **cmd, int *status)
{
	char	**env_exp;
	char	*name;
	int		ret;

	ret = 0;
	env_exp = EXPORT;
	name = get_cmd_path(*cmd);
	if (name && fork_exec(env_exp, name, cmd) && (ret = 1))
		wait(status);
	else if (fork_exec(env_exp, *cmd, cmd) && (ret = 1))
		wait(status);
	g_child = 0;
	free(name);
	ft_arr_free((void **)env_exp);
	return (ret);
}
