/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mshenv_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 12:34:36 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/08 12:44:01 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"
#include "libprintf/libprintf.h"

int			env_update(char *key, char *val, char **env, char **env_end)
{
	char	*entry;
	char	*init_key;
	size_t	len;
	size_t	len1;

	if (!(entry = key, env, env_end))
	{
		WARN(g_warn_notf, "key");
		return (0);
	}
	init_key = entry;
	while (init_key != '=')
		init_key++;
	init_key++;
	len = ft_strlen(init_key);
	len1 = ft_strlen(key);
	if (len1 <= len)
}
