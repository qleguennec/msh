/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_dict.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 23:18:18 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/28 22:04:39 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"
#include "libprintf/libprintf.h"

int		builtin_dict(t_vll *cmd)
{
	(void)cmd;
	ft_printf("used: %lu/%lu\ndel: %lu/%lu\n"
			, g_env.used, g_env.total, g_env.del, g_env.total);
	return (0);
}
