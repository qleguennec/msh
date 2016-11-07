/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 20:58:27 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/07 18:05:56 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"
#include "libft/libft.h"
#include "libgnl/libgnl.h"
#include <stdio.h>

static int		loop(char **env, char **env_end)
{
	int			ret;
	char		**s;
	char		buf[QUERY_BUFSIZ];
	char		**path;

	BZERO(t_vect, buf);
	BZERO(t_vect, line);
	msh_env_query(buf, "PATH=", env, env_end);
	path = split(buf, );
	while (42)
	{
		msh_prompt();
		if ((ret = get_next_line(0, &buf, &line)) == -1)
			msh_exit(g_read_err);
		if (!ret)
			break ;
		vect_mset_end(&line, '\0', 1);
		s = split(line.data, &ft_isspace);
		line.used = 0;
	}
	return (0);
}

int				main(int argc, char **argv, char **environ)
{
	char		**env_end;

	(void)argc;
	(void)argv;
	env_end = environ;
	while (*environ && *(env_end + 1))
		env_end++;
	ft_qsort((void **)environ, env_end - environ, &env_cmp, 0);
	return (loop(environ, env_end));
}
