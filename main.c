/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 20:58:27 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/28 21:27:37 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"
#include "msh_alias.h"
#include "libft/malloc.h"
#include "libft/libft.h"
#include <dirent.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

static void		init(char **environ)
{
	size_t		i;

	BZERO(g_buf);
	dict_str_init(&g_env, 16);
	while (*environ)
		IMPORT_ADD(*environ++);
	msh_env();
	dict_str_init(&g_alias, 16);
	i = -1;
	while (++i < LEN(g_alias_def))
		AL_IMPORT_ADD((char *)g_alias_def[i]);
}

static void		deinit(void)
{
	dict_free(&g_env);
	dict_free(&g_alias);
	free(g_buf.data);
}

int				main(int argc, char **argv, char **environ)
{
	int			status;

	(void)argc;
	(void)argv;
	init(environ);
	signal(SIGINT, &sighandle_int);
	g_child = 0;
	while (msh_read(&status))
		;
	deinit();
	return (status);
}
