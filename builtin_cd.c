/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 12:28:10 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/08 12:35:43 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

int			builtin_cd(char **cmd, char **path, char **env, char **env_end)
{
	char	*dir;
	char	ans[QUERY_BUFSIZ];

	if (cmd[1])
		dir = cmd[1];
	else
	{
		msh_env_query(ans, "HOME", env, env_end);
		dir = ans;
	}
}
