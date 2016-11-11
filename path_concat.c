/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_concat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 22:37:18 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/11 00:26:59 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/malloc.h"

char			*path_concat(char *a, char *b)
{
	char		*ret;
	size_t		alen;
	size_t		blen;
	size_t		retlen;
	int			slash;

	alen = ft_strlen(a);
	blen = ft_strlen(b);
	slash = !(a[alen - 1] == '/' || b[0] == '/');
	retlen = alen + blen + slash;
	MALLOC(ret, retlen + 1);
	while (*a)
		*ret++ = *a++;
	if (slash)
		*ret++ = '/';
	while (*b)
		*ret++ = *b++;
	*ret = '\0';
	return (ret - retlen);
}
