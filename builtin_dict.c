/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_dict.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 23:18:18 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/25 15:23:20 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"
#include "libprintf/libprintf.h"

int		builtin_dict(char **cmd)
{
	cmd++;
	if (!*cmd)
	{
		ft_printf("used: %lu/%lu\ndel: %lu/%lu\n"
			, g_env.used, g_env.total, g_env.del, g_env.total);
		return (0);
	}
	if (!ft_strcmp(*cmd, "used"))
		ft_printf("used: %lu/%lu\n", g_env.used, g_env.total);
	if (!ft_strcmp(*cmd, "del"))
		ft_printf("del: %lu/%lu\n", g_env.del, g_env.total);
	return (0);
}
