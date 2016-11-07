/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:10:12 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/07 17:59:00 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "malloc.h"

static char		*next_word(char **s, int (*f)(char))
{
	char		*r;

	while (**s && f(**s))
		(*s)++;
	r = *s;
	while (**s && !f(**s))
		(*s)++;
	return (r);
}

char			**split(char *s, int (*f)(char))
{
	size_t		count;
	char		*s1;
	char		*buf;
	char		**ret;

	count = 0;
	s1 = s;
	while (*s1 && next_word(&s1, f))
		count++;
	MALLOC(ret, sizeof(*ret) * (count + 1));
	while (*s)
	{
		buf = next_word(&s, f);
		MALLOC(*ret, s - buf);
		ft_memcpy(*ret, buf, s - buf);
		ret++;
	}
	*ret = NULL;
	return (ret - count);
}
