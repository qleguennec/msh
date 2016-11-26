/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 21:12:51 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/25 15:50:09 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"
#include "libprintf/libprintf.h"

void			msh_prompt(void)
{
	t_dict_ent		*pwd;
	t_dict_ent		*user;
	t_dict_ent		*status;

	pwd = LOOKUP("PWD");
	user = LOOKUP("USER");
	status = LOOKUP("?");
	if (status)
		ft_printf("%s ", status->val.data);
	if (user)
		ft_printf("(%s) ", user->val.data);
	if (pwd)
		ft_printf("%s ", pwd->val.data);
	ft_printf("$> ");
}
