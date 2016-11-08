/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   query.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:24:07 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/08 12:39:38 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*query(char *str, char **fst, char **lst)
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
