/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_warn.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:10:27 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/14 15:40:22 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_WARN_H
# define MSH_WARN_H

# define W_OOB		"msh, '%s()': too large for buffer\n"
# define W_NOTF		"msh, '%s()': '%s' not found\n"
# define W_DENY		"msh, '%s()': cannot access '%s', denied\n"
# define W_NOENV	"msh, '%s()': '$%s' not set\n"
# define W_EXEC		"msh, '%s()': exec failed with status %d\n"
# define W_CHDIR	"msh, '%s()': chdir failed\n"
# define W_BIARG	"msh, '%s()':option requires an argument -- '%s'\n"
# define W_NOOPT	"msh, '%s()': unknown option -- '%c'\n"
# define W_NUMARG	"msh, '%s()': %s: numeric argument required\n"
# define W_MANYARG	"msh, '%s'(): too many arguments\n";
# define W_IO		"msh, input/output error\n"

#endif
