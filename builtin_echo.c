/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 02:08:33 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/11 02:42:12 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"
#include "libprintf/libprintf.h"

int			builtin_echo(t_dict *env, char **cmd)
{
	(void)env;
	cmd++;
	while (*cmd)
		ft_printf("%s\n", *cmd++);
	return (0);
}
