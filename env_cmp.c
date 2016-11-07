/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:32:58 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/07 17:52:35 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int			env_cmp(void *p1, void *p2)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = p1;
	s2 = p2;
	while (*s1 == *s2 && *s1 != '=')
	{
		s1++;
		s2++;
	}
	return (*((unsigned char *)s1) - *((unsigned char *)s2));
}
