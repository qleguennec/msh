/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 15:25:53 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/28 23:44:44 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"
#include "msh_alias.h"
#include <unistd.h>

static t_vect	*expand(t_vect *v, void *null)
{
	t_dict_ent		*home;
	t_vect			*new;
	unsigned char	*s;

	(void)null;
	s = v->data;
	if (s[0] == '~')
	{
		WLOOKUP(home, "HOME");
		if (!home)
			return (NULL);
		new = vect_new(NULL, home->val.used + v->used - 1);
		vect_add(new, home->val.data, home->val.used);
		vect_add(new, v->data + 1, v->used - 1);
		return (new);
	}
	return (NULL);
}

static t_vll	*read_expand()
{
	t_vll		*ret;

	ret = VLL_VSPLIT(g_buf, WHITESPACE);
	vll_vect_map(ret, &expand, NULL);
	VLL_VLL_SPLIT(ret, ";");
	return (ret);
}

int				msh_read(int *status)
{
	char	c;
	int		eval_ret;
	int		read_ret;
	int		ret;
	t_vll	*cmd;

	msh_prompt();
	g_buf.used = 0;
	while ((read_ret = read(0, &c, 1) == 1) && c != '\n')
		vect_add(&g_buf, &c, 1);
	if (read_ret <= 0)
		return (0);
	if (!g_buf.used)
		return (1);
	cmd = read_expand();
	if ((eval_ret = msh_eval(cmd, status)) == -1)
		ret = 0;
	else
	{
		ret = 1;
		msh_status(eval_ret, *status);
	}
	vll_free(cmd);
	return (ret);
}
