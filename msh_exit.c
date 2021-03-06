/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 14:57:38 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/14 15:23:37 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf/libprintf.h"
#include <stdlib.h>
#include <stdarg.h>

void		msh_exit(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	ft_vdprintf(2, format, ap);
	exit(1);
}
