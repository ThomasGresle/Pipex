/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:02:52 by tgresle           #+#    #+#             */
/*   Updated: 2021/12/14 12:05:44 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <errno.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
void	parse_path_and_exec(char **envp, char *cmd);
int		child_process(int fd, char *cmd, int *end, char **envp);
int		parent_process(int fd, char *cmd, int *end, char **envp);
char	*ft_strjoin_bis(char *s1, char *s2);
char	*ft_get_path(char **envp, char *path);
void	add_slash(char **cmd_path);
void	ft_putchar(char c);
void	ft_putstr(char *s);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		loop_split(const char *s, int *i, char c, char **str);

#endif