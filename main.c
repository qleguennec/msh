/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 20:58:27 by qle-guen          #+#    #+#             */
/*   Updated: 2016/10/13 21:33:47 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		"msh.h"
#include		"libft/libft.h"
#include		"libgnl/libgnl.h"

int				main(void)
{
	int			ret;

	ZERO(t_vect, buf);
	ZERO(t_read, st_r);
	ZERO(t_eval, st_e);
	while (42)
	{
		msh_prompt();
		if ((ret = get_next_line(FD_IN, &st_r.line, &buf)) == -1)
			msh_exit(g_read_err);
		if (!ret)
			break ;
		st_r.line.used = 0;
		msh_eval(&st_r, &st_e);
	}
}
