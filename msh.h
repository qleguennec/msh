/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 21:00:15 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/26 13:46:58 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_H
# define MSH_H

# include "msh_warn.h"
# include "libvect/libvect.h"
# include "libdict/libdict.h"
# include "libprintf/libprintf.h"
# include <stdio.h>

# define STATUS_NOTF	127
# define QUERY_BUFSIZ	1024

# define WARN(w,...)	ft_dprintf(2,w,__FUNCTION__,__VA_ARGS__)

# define LOOKUP(k)		dict_lookup(&g_env, k)
# define WLOOKUP(e, k)	if (!(e = LOOKUP(k))) WARN(W_NOENV, k)
# define LOOKUPV(e, k)	((e = LOOKUP(k)) ? (e->val.data) : NULL)
# define WLOOKUPV(e, k)	{WLOOKUP(e, k); return (e ? ent->val.data : NULL);}
# define SET(k, v)		dict_str_set(&g_env, k, v)
# define DELETE(k)		dict_del(&g_env, k)
# define IMPORT(k)		dict_str_import(&g_env, k, "=", &dict_str_set)
# define EXPORT			dict_str_export(&g_env, "=")

int						msh_eval(char **cmd, int *status);
int						msh_exec(char **cmd, int *status);
int						msh_read(int *status);
void					msh_env(void);
void					msh_exit(const char *format, ...);
void					msh_loop(void);
void					msh_prompt(void);
void					msh_status(int run_ret, int status);

int						builtin_cd(char **cmd);
int						builtin_echo(char **cmd);
int						builtin_env(char **cmd);
int						builtin_dict(char **cmd);
int						builtin_setenv(char **cmd);
int						builtin_unsetenv(char **cmd);
int						builtin_clearenv(char **cmd);

void					sighandle_int(int signo);

char					*get_cmd_path(char *cmd);
char					*path_concat(char *a, char *b);
int						fork_exec(char **env_exp, char *name, char **cmd);

int						g_child;
t_dict					g_env;
t_vect					g_buf;

#endif
