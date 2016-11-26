/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 15:25:53 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/26 14:21:12 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"
#include <unistd.h>

static char	*read_tilde_expand(char *cmd)
{
	size_t		len;
	t_dict_ent	*home;
	t_vect		cmd_new;

	if (!(home = LOOKUP("HOME")))
		return (NULL);
	len = ft_strlen(cmd);
	BZERO(cmd_new);
	vect_add(&cmd_new, home->val.data, home->val.used - 1);
	vect_add(&cmd_new, cmd + 1, len);
	return (cmd_new.data);
}

static char	**msh_split(t_vect *line)
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
			if (!(buf = read_tilde_expand(cmd[i])))
				break ;
			free(cmd[i]);
			cmd[i] = buf;
		}
	}
	return (cmd);
}

int			msh_read(int *status)
{
	char	**cmd;
	char	c;
	int		read_ret;
	int		eval_ret;

	msh_prompt();
	g_buf.used = 0;
	while ((read_ret = read(0, &c, 1) == 1) && c != '\n')
		vect_add(&g_buf, &c, 1);
	if (read_ret <= 0)
		return (0);
	if (!g_buf.used)
		return (1);
	if (*(cmd = msh_split(&g_buf)))
	{
		if ((eval_ret = msh_eval(cmd, status)) == -1)
		{
			ft_arr_free((void **)cmd);
			return (0);
		}
		else
			msh_status(eval_ret, *status);
		ft_arr_free((void **)cmd);
	}
	return (1);
}
