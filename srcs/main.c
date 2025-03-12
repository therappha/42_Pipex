/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:23:23 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/03/12 20:19:07 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av, char **envp)
{
	char	*path;
	int		pid;
	int		pipe_fd[2];

	if (ac != 5)
		return (0);
	path = check_envp(envp);
	if (!path)
		return (ft_printf("Invalid environment!"));
	pipe(pipe_fd);
	pid = fork();
	if (pid == 0)
		handle_child(av, envp, path, pipe_fd);
	else
	{
		wait(NULL);
		handle_parent(av, envp, path, pipe_fd);
	}
	(void)av;
	ft_printf("finished execution!\n");

}
