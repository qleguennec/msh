/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 21:00:15 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/07 17:55:24 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_H
# define MSH_H

# include "libvect/libvect.h"

# define QUERY_BUFSIZ	1024

static char				*g_prompt = "$> ";
static char				*g_read_err = "read error";

void					msh_exit(const char *format, ...);
void					msh_prompt(void);
int						env_cmp(void *s1, void *s2);
void					msh_env_query(char *dest, char *qu, char **env, char **env_end);
int						iscolon(int c);
char					**split(char *s, int (*f)(int));

#endif
