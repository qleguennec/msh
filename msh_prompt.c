/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 21:12:51 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/14 14:17:53 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"
#include "libprintf/libprintf.h"

void			msh_prompt(t_dict *env)
{
	t_dict_ent		*pwd;
	t_dict_ent		*user;
	t_dict_ent		*status;

	pwd = dict_lookup(env, "PWD");
	user = dict_lookup(env, "USER");
	status = dict_lookup(env, "?");
	if (status)
		ft_printf("%s ", status->val.data);
	if (user)
		ft_printf("(%s) ", user->val.data);
	if (pwd)
		ft_printf("%s ", pwd->val.data);
	ft_printf("$> ");
}
