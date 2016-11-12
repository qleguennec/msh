/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 23:30:29 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/12 21:45:25 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

int		builtin_setenv(t_dict *env, char **cmd)
{
	while (*++cmd)
	{
		printf("%s\n", *cmd);
		dict_str_import(env, *cmd, "=", &dict_str_set);
	}
	return (0);
}
