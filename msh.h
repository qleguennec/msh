/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 21:00:15 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/28 21:31:09 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_H
# define MSH_H

# include "msh_warn.h"
# include "libvect/libvect.h"
# include "libdict/libdict.h"
# include "libprintf/libprintf.h"
# include "libvll/libvll.h"
# include <stdio.h>

# define STATUS_NOTF	127
# define QUERY_BUFSIZ	1024

# define WARN(w,...)	ft_dprintf(2,w,__FUNCTION__,__VA_ARGS__)

# define LOOKUP(k)		dict_lookup(&g_env, k)
# define ALOOKUP(k)		dict_lookup(&g_alias, k)
# define WLOOKUP(e, k)	if (!(e = LOOKUP(k))) WARN(W_NOENV, k)
# define LOOKUPV(e, k)	((e = LOOKUP(k)) ? (e->val.data) : NULL)
# define WLOOKUPV(e, k)	{WLOOKUP(e, k); return (e ? ent->val.data : NULL);}
# define SET(k, v)		dict_str_set(&g_env, k, v)
# define DELETE(k)		dict_del(&g_env, k)
# define IMPORT_ADD(k)	dict_str_import(&g_env, k, "=", DICT_IMPORT_SET)
# define IMPORT_SET(k)	dict_str_import(&g_env, k, "=", DICT_IMPORT_ADD)
# define EXPORT			dict_str_export(&g_env, "=")

# define AL_IMPORT_ADD(k)	dict_str_import(&g_alias, k, "=", DICT_IMPORT_SET)
# define AL_IMPORT_SET(k)	dict_str_import(&g_alias, k, "=", DICT_IMPORT_ADD)

int						msh_eval(t_vll *cmd, int *status);
int						msh_exec(t_vll *cmd, int *status);
int						msh_read(int *status);
void					msh_env(void);
void					msh_exit(const char *format, ...);
void					msh_loop(void);
void					msh_prompt(void);
void					msh_status(int run_ret, int status);

int						builtin_cd(t_vll *cmd);
int						builtin_echo(t_vll *cmd);
int						builtin_env(t_vll *cmd);
int						builtin_dict(t_vll *cmd);
int						builtin_setenv(t_vll *cmd);
int						builtin_unsetenv(t_vll *cmd);
int						builtin_clearenv(t_vll *cmd);

void					sighandle_int(int signo);

char					*get_cmd_path(char *cmd);
char					*path_concat(char *a, char *b);
int						fork_exec(t_vll *env_exp, char *name, t_vll *cmd);

int						g_child;
t_dict					g_env;
t_dict					g_alias;
t_vect					g_buf;

#endif
