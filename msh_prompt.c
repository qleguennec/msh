/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 21:12:51 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/12 19:32:21 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"
#include "libprintf/libprintf.h"

void			msh_prompt(t_dict *env, int run_ret)
{
	t_dict_ent	*pwd;
	t_dict_ent	*user;

	pwd = dict_lookup(env, "PWD");
	user = dict_lookup(env, "USER");
	ft_printf("%d ", run_ret);
	if (user)
		ft_printf("(%s) ", user->val.data);
	if (pwd)
		ft_printf("%s ", pwd->val.data);
	ft_printf("$> ");
}
