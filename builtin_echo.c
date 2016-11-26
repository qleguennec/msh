/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 02:08:33 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/25 15:23:34 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"
#include "libprintf/libprintf.h"

int			builtin_echo(char **cmd)
{
	while (*++cmd)
		ft_printf(cmd + 1 ? "%s " : "%s", *cmd);
	ft_printf("\n");
	return (0);
}
