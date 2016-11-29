/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 02:08:33 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/28 23:44:33 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"
#include "libprintf/libprintf.h"

int			builtin_echo(t_vll *cmd)
{
	t_vll_node	*n;

	n = cmd->head;
	while (n)
	{
		ft_printf(n->next ? "%s " : "%s", VLL_DATA(n));
		n = n->next;
	}
	ft_printf("\n");
	return (0);
}
