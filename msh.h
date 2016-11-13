/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 21:00:15 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/13 19:46:34 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_H
# define MSH_H

# include "libvect/libvect.h"
# include "libdict/libdict.h"
# include <stdio.h>

# define STATUS_NOTF	127
# define QUERY_BUFSIZ	1024

# define WARN(w,...)		ft_dprintf(2,w,__FUNCTION__,__VA_ARGS__)

void					msh_exit(const char *format, ...);
void					msh_prompt(t_dict *env, int run_ret);
int						msh_exec(t_dict *env, char **cmd, int *status);
char					**msh_read(t_dict *env, t_vect *line);

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

static char				*g_read_err = "read error";

static const char		*g_warn_oob = "msh, '%s()': too large for buffer\n";
static const char		*g_warn_notf = "msh, '%s()': '%s' not found\n";
static const char		*g_warn_deny = "msh, '%s()': cannot access '%s', denied\n";
static const char		*g_warn_noenv = "msh, '%s()': '$%s' not set\n";
static const char		*g_warn_exec = "msh, '%s()': exec failed with status %d\n";

static const char		*g_warn_chdir = "msh, '%s()': chdir failed\n";
static const char		*g_warn_binoarg = "msh, '%s()': option requires an argument -- '%s'\n";
static const char		*g_warn_unkopt = "msh, '%s()': unknown option -- '%c'\n";

#endif
