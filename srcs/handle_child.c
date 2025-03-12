/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:50:58 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/03/12 20:40:17 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
char	**ft_split_path(char *env_path, char *cmd);
char	*append_cmd(char *path, char *cmd);

void	handle_child(char **av, char **envp, char *env_path, int *pipe_fd)
{
	int fd;
	char **cmd;
	char **split_path;

	close(pipe_fd[0]);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Could not open file1\n");
		return ;
	}
	cmd = ft_split(av[2], ' ');
	split_path = ft_split_path(env_path, cmd[0]);
	env_path = check_cmdpath(split_path);
	if (!env_path)
	{
		//free_split(split_path);
		//free_split(cmd_path);
		ft_printf("command not found!\n");
		return ;
	}
	dup2(fd, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(fd);
	close(pipe_fd[1]);

	execve(env_path, cmd, envp);
}
char **ft_split_path(char *env_path, char *cmd)
{
	char	**split_path;
	char	*slashcmd;
	int	i;

	slashcmd = ft_strjoin("/", cmd);
	split_path = ft_split(env_path, ':');
	i = 0;
	while (split_path[i])
	{
		split_path[i] = append_cmd(split_path[i], slashcmd);
		i++;
	}
	free(slashcmd);
	return (split_path);

}
char	*append_cmd(char *path, char *cmd)
{
	char	*temp;

	temp = ft_strjoin(path, cmd);
	free(path);
	return (temp);
}
