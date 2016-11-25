/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:03:07 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/25 14:49:01 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

void	msh_loop(void)
{
	int		read_status;

	g_eintr = 0;
	read_status = msh_read();
	if (read_status)
		msh_loop();
}
