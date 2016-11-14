/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 23:30:29 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/14 16:14:42 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

int		builtin_setenv(t_dict *env, char **cmd)
{
	while (*++cmd)
		dict_str_import(env, *cmd, "=", &dict_str_set);
	return (0);
}
