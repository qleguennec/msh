/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 21:00:15 by qle-guen          #+#    #+#             */
/*   Updated: 2016/10/18 23:20:39 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_H
# define MSH_H

# define FD_IN			0
# include				"libvect/libvect.h"

typedef struct			s_read
{
	t_vect				line;
}						t_read;

typedef struct			s_eval
{
}						t_eval;

static char				*g_prompt = "$> ";
static char				*g_read_err = "read error";

void					msh_eval(t_read *st_r, t_eval *st_e);
void					msh_exit(const char *format, ...);
void					msh_prompt(void);

#endif
