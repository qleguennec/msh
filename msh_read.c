/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 15:25:53 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/14 15:26:05 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"
#include "libprintf/libprintf.h"

char	*read_tilde_expand(t_dict *env, char *cmd)
{
	size_t		len;
	t_dict_ent	*home;
	t_vect		cmd_new;

	if (!(home = dict_lookup(env, "HOME")))
		return (NULL);
	len = ft_strlen(cmd);
	BZERO(cmd_new);
	vect_add(&cmd_new, home->val.data, home->val.used - 1);
	vect_add(&cmd_new, cmd + 1, len);
	return (cmd_new.data);
}

char	**msh_read(t_dict *env, t_vect *line)
{
	char	**cmd;
	char	*buf;
	size_t	i;

	cmd = (char **)VSPLIT((*line), WHITESPACE);
	i = -1;
	while (cmd[++i])
	{
		if (*cmd[i] == '~')
		{
			if (!(buf = read_tilde_expand(env, cmd[i])))
				break ;
			free(cmd[i]);
			cmd[i] = buf;
		}
	}
	return (cmd);
}
