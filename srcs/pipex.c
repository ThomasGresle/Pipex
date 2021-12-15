/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:16:18 by tgresle           #+#    #+#             */
/*   Updated: 2021/12/15 17:47:58 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	clean_fd2(int fd1, char **av)
{
	if (access(av[4], F_OK) < 0)
	{
		ft_putstr("no such file or directory: ");
		ft_putstr(av[4]);
		ft_putchar('\n');
	}
	else
	{
		ft_putstr("permission denied: ");
		ft_putstr(av[4]);
		ft_putchar('\n');
	}
	close(fd1);
}

void	clean(char **av)
{
	if (access(av[1], F_OK) < 0)
	{
		ft_putstr("no such file or directory: ");
		ft_putstr(av[1]);
		ft_putchar('\n');
	}
	else
	{
		ft_putstr("permission denied: ");
		ft_putstr(av[1]);
		ft_putchar('\n');
	}
}

void	pipex(int fd1, int fd2, char **argv, char **envp)
{
	int		end[2];
	pid_t	id;

	if (pipe(end) < 0)
	{
		ft_putstr_fd("pipe error\n");
		close(fd1);
		close(fd2);
		exit(-1);
	}
	id = fork();
	if (id == 0)
	{
		close(end[1]);
		parent_process(fd2, argv[3], end, envp);
	}
	else
	{
		close(end[0]);
		child_process(fd1, argv[2], end, envp);
	}
}

int	main(int ac, char **av, char **envp)
{
	int	fd1;
	int	fd2;

	if (ac != 5)
	{
		ft_putstr("use: ./pipex file1 cmd1 cmd2 file2\n");
		return (-1);
	}
	fd1 = open(av[1], O_RDONLY);
	if (fd1 < 0)
	{
		clean(av);
		return (-1);
	}
	fd2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd2 < 0)
	{
		clean_fd2(fd1, av);
		return (-1);
	}
	pipex(fd1, fd2, av, envp);
	return (0);
}
