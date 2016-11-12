/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 23:30:29 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/12 00:53:18 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

int		builtin_setenv(t_dict *env, char **cmd)
{
	while (*++cmd)
	{
		printf("%s\n", *cmd);
		dict_str_import(env, *cmd, "=");
	}
	return (0);
}
