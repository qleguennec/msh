/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_eval.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:01:40 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/25 15:48:17 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"
#include "libft/libft.h"

static int		builtin_exec(char **cmd, int *status)
{
	int			(*b)(char **);

	b = NULL;
	if (!b && !ft_strcmp(*cmd, "cd"))
		b = &builtin_cd;
	if (!b && !ft_strcmp(*cmd, "echo"))
		b = &builtin_echo;
	if (!b && !ft_strcmp(*cmd, "env"))
		b = &builtin_env;
	if (!b && !ft_strcmp(*cmd, "dict"))
		b = &builtin_dict;
	if (!b && !ft_strcmp(*cmd, "setenv"))
		b = &builtin_setenv;
	if (!b && !ft_strcmp(*cmd, "unsetenv"))
		b = &builtin_unsetenv;
	if (!b && !ft_strcmp(*cmd, "clearenv"))
		b = &builtin_clearenv;
	if (!b)
		return (0);
	*status = b(cmd);
	return (1);
}

int			msh_eval(char **cmd, int *status)
{
	if (!ft_strcmp(*cmd, "exit"))
		return (-1);
	if (builtin_exec(cmd, status))
		return (1);
	if (msh_exec(cmd, status))
		return (1);
	WARN(W_NOTF, *cmd);
	return (0);
}
