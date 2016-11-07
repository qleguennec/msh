/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_query.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:24:07 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/07 17:48:52 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "msh.h"
#include "libprintf/libprintf.h"

static char		*query(char *str, char **fst, char **lst)
{
	char	**n;
	int		cmp;

	if (env_cmp(str, *fst) < 0 || env_cmp(str, *lst) > 0)
		return (NULL);
	if (fst == lst)
		return (!env_cmp(str, *fst) ? *fst : NULL);
	if (fst == lst - 1)
	{
		cmp = env_cmp(str, *fst);
		if (!cmp)
			return (*fst);
		if (cmp > 0)
			return (!env_cmp(str, *lst) ? *lst : NULL);
		else
			return (NULL);
	}
	n = fst + ((lst - fst) / 2);
	cmp = env_cmp(str, *n);
	if (!cmp)
		return (*n);
	if (cmp > 0)
		return (query(str, n, lst));
	else
		return (query(str, fst, n));
}

void			msh_env_query(char *dest, char *qu, char **env, char **env_end)
{
	size_t		qlen;
	size_t		reslen;
	char		*res;

	qlen = ft_strlen(qu);
	res = query(qu, env, env_end);
	if (!res)
		ft_dprintf(2, "%s not found in env\n", qu);
	while (*res != '=')
		res++;
	res++;
	reslen = ft_strlen(res);
	if (reslen + 1 > QUERY_BUFSIZ) //todo error
		return ;
	ft_strcpy(dest, res + 1);
}
