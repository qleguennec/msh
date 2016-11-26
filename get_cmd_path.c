/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 23:51:19 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/25 16:46:14 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"
#include "libdict/libdict.h"
#include <dirent.h>

static void		read_dir(DIR *dir, char *path, char *cmd, char **match)
{
	struct dirent	*ent;

	while ((ent = readdir(dir)))
	{
		if (!ft_strcmp(cmd, ent->d_name))
			*match = path_concat(path, cmd);
	}
	closedir(dir);
}

char			*get_cmd_path(char *cmd)
{
	DIR			*dir;
	char		**str_path;
	char		*ret;
	size_t		i;
	t_dict_ent	*path;

	WLOOKUP(path, "PATH");
	if (!path)
		return (NULL);
	str_path = (char **)VSPLIT(path->val, ":");
	i = 0;
	ret = NULL;
	while (str_path[i])
	{
		if (!ret && (dir = opendir(str_path[i])))
			read_dir(dir, str_path[i], cmd, &ret);
		free(str_path[i++]);
	}
	free(str_path);
	return (ret);
}
