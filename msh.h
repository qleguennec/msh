/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 21:00:15 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/25 14:05:47 by qle-guen         ###   ########.fr       */
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

# define WARN(w,...)		ft_dprintf(2,w,__FUNCTION__,__VA_ARGS__)

int						msh_eval(t_dict *env, char **cmd, int *status);
int						msh_exec(t_dict *env, char **cmd, int *status);
int						msh_read(void);
void					msh_env(t_dict *env);
void					msh_exit(const char *format, ...);
void					msh_loop(void);
void					msh_prompt(t_dict *env);
void					msh_status(t_dict *env, int run_ret, int status);

char					*get_cmd_path(t_dict *env, char *cmd);
char					*path_concat(char *a, char *b);
int						fork_exec(char **env_exp, char *name, char **cmd);

int						builtin_cd(t_dict *env, char **cmd);
int						builtin_echo(t_dict *env, char **cmd);
int						builtin_env(t_dict *env, char **cmd);
int						builtin_dict(t_dict *env, char **cmd);
int						builtin_setenv(t_dict *env, char **cmd);
int						builtin_unsetenv(t_dict *env, char **cmd);
int						builtin_clearenv(t_dict *env, char **cmd);

void					sighandle_int(int signo);

int						g_child;
int						g_eintr;
t_dict					g_env;
t_vect					g_buf;

#endif
