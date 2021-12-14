/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:16:08 by tgresle           #+#    #+#             */
/*   Updated: 2021/12/14 12:41:50 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	clean_matrice(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		i++;
	}
	free(mat[i]);
	free(mat);
}

void	error_cmd(char *str, char **mat1, char **mat2)
{
	ft_putstr("command not found\n");
	free(str);
	clean_matrice(mat1);
	clean_matrice(mat2);
}

void	parse_path_and_exec(char **envp, char *cmd)
{
	char	*cmd_and_path;
	char	*envp_cmd_paths;
	char	**cmd_path;
	char	**cmd_and_options;
	int		i;

	cmd_and_path = NULL;
	envp_cmd_paths = NULL;
	cmd_path = NULL;
	cmd_and_options = NULL;
	i = -1;
	envp_cmd_paths = ft_get_path(envp, "PATH=");
	cmd_path = ft_split(envp_cmd_paths, ':');
	add_slash(cmd_path);
	cmd_and_options = ft_split(cmd, ' ');
	while (cmd_path[++i])
	{
		cmd_and_path = ft_strjoin(cmd_path[i], cmd_and_options[0]);
		perror(cmd_and_options[0]);
		execve(cmd_and_path, cmd_and_options, envp);
		free(cmd_and_path);
	}
	error_cmd(envp_cmd_paths, cmd_path, cmd_and_options);
}

int	parent_process(int fd, char *cmd, int *end, char **envp)
{
	if (dup2(end[0], STDIN_FILENO) < 0)
		return (0);
	close(end[0]);
	if (dup2(fd, STDOUT_FILENO) < 0)
		return (0);
	close(fd);
	parse_path_and_exec(envp, cmd);
	return (1);
}

int	child_process(int fd, char *cmd, int *end, char **envp)
{
	int	status;

	status = 0;
	if (dup2(fd, STDIN_FILENO) < 0)
		return (0);
	close(fd);
	if (dup2(end[1], STDOUT_FILENO) < 0)
		return (0);
	close(end[1]);
	parse_path_and_exec(envp, cmd);
	return (1);
}
