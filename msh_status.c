/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_status.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:05:21 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/14 17:07:12 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"
#include "libprintf/libprintf.h"
#include <sys/types.h>

void		msh_status(t_dict *env, int run_ret, int status)
{
	int		st;
	char	buf[20];

	if (!run_ret)
		st = STATUS_NOTF;
	else
	{
		if (WIFEXITED(status))
			st = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			st = WTERMSIG(status);
		else if (WIFSTOPPED(status))
			st = WSTOPSIG(status);
		else
			st = 0;
	}
	ft_sprintf(buf, "?=%d", st);
	dict_str_import(env, buf, "=", &dict_str_set);
}
