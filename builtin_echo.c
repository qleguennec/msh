/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 02:08:33 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/13 19:26:59 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"
#include "libprintf/libprintf.h"

int			builtin_echo(t_dict *env, char **cmd)
{
	(void)env;
	while (*++cmd)
		ft_printf(cmd + 1 ? "%s " : "%s", *cmd);
	ft_printf("\n");
	return (0);
}
