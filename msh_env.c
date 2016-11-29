/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:07:24 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/28 21:28:28 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"
#include "libprintf/libprintf.h"

void		msh_env(void)
{
	int			shlvl_int;
	t_dict_ent	*shlvl;

	if (!(shlvl = LOOKUP("SHLVL")))
		dict_str_import(&g_env, "SHLVL=1", "=", DICT_IMPORT_ADD);
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
