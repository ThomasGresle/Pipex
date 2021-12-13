/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:02:52 by tgresle           #+#    #+#             */
/*   Updated: 2021/12/13 16:33:53 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <sys/types.h>
# include <errno.h>
# include "../Libft/libft.h"
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

void    parse_path_and_exec(char **envp, char *cmd);
int     child_process(int fd, char *cmd, int *end, char **envp);
int     parent_process(int fd, char *cmd, int *end, char **envp);
char	*ft_strjoin_bis(char *s1, char *s2);
char    *ft_get_path(char **envp, char *path);
void    add_slash(char **cmd_path);

# endif