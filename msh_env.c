/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:07:24 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/14 17:19:31 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"
#include "libprintf/libprintf.h"

void		msh_env(t_dict *env)
{
	int			shlvl_int;
	t_dict_ent	*shlvl;

	if (!(shlvl = dict_lookup(env, "SHLVL")))
		dict_str_import(env, "SHLVL=1", "=", &dict_str_add);
	else if (shlvl->val.used == 1 || !VONLY(shlvl->val, DIGIT))
	{
		shlvl->val.used = 0;
		vect_addstr(&shlvl->val, "1");
	}
	else
	{
		shlvl_int = ft_atoi(shlvl->val.data);
		shlvl->val.used = 0;
		vect_fmt(&shlvl->val, "%d", ++shlvl_int);
	}
}
