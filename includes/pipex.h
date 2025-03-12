/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:34:13 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/03/12 20:15:07 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libs/libft/includes/libft.h"
# include <unistd.h>
# include <sys/wait.h>

char	*check_envp(char **envp);
void	handle_child(char **av, char **envp, char *env_path, int *pipe_fd);
void	handle_parent(char **av, char **envp, char *env_path, int *pipe_fd);
char	*check_cmdpath(char **split_path);
char	*append_cmd(char *path, char *cmd);
char **ft_split_path(char *env_path, char *cmd);

#endif
