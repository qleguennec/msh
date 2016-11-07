/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 21:00:15 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/07 22:51:42 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_H
# define MSH_H

# include "libvect/libvect.h"
# include <stdio.h>

# define ERR_EXEC		-1
# define ERR_FORK		-2
# define QUERY_BUFSIZ	1024

# define WARN(w,...)		ft_dprintf(2,w,__FUNCTION__,__VA_ARGS__)

static char				*g_prompt = "$> ";
static char				*g_read_err = "read error";

void					msh_exit(const char *format, ...);
void					msh_prompt(void);
int						env_cmp(void *s1, void *s2);
size_t					msh_env_query(char *dest, char *qu, char **env, char **env_end);
int						iscolon(int c);
char					**nsplit(char *s, size_t n, int (*f)(int));
void					arr_free(void **a);
char					*path_concat(char *a, char *b);

static const char		*g_warn_oob = "msh: '%s()': too large for buffer\n";
static const char		*g_warn_notf = "msh: '%s()': '%s' not found\n";
static const char		*g_warn_fork = "msh: '%s()': fork failed with status %d\n";
static const char		*g_warn_exec = "msh: '%s()': execve failed with status %d\n";

#endif
