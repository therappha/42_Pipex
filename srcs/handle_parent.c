/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_parent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:51:40 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/03/12 20:40:35 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	handle_parent(char **av, char **envp, char *env_path, int *pipe_fd)
{
	int fd;
	char **cmd;
	char **split_path;
	char *cmdpath;

	close(pipe_fd[1]);
	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd == -1)
	{
		ft_printf("Could not open file1\n");
		return ;
	}
	cmd = ft_split(av[3], ' ');
	split_path = ft_split_path(env_path, cmd[0]);
	cmdpath = check_cmdpath(split_path);
	if (!cmdpath)
	{
		//free_split(split_path);
		//free_split(cmd_path);
		ft_printf("command not found!\n");
		return ;
	}

	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(pipe_fd[0]);
	close(fd);

	execve(cmdpath, cmd, envp);
}
