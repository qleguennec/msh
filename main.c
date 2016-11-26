/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 20:58:27 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/26 14:17:55 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"
#include "libft/malloc.h"
#include "libft/libft.h"
#include <dirent.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

int				main(int argc, char **argv, char **environ)
{
	int			status;

	(void)argc;
	(void)argv;
	dict_str_init(&g_env, 16);
	while (*environ)
		dict_str_import(&g_env, *environ++, "=", &dict_str_add);
	msh_env();
	BZERO(g_buf);
	signal(SIGINT, &sighandle_int);
	g_child = 0;
	while (msh_read(&status))
		;
	free(g_buf.data);
	dict_free(&g_env);
	return (status);
}
