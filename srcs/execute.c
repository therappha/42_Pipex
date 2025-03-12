/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:28:32 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/03/12 18:33:57 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char *check_cmdpath(char **split_path)
{
	int		i;
	char	*valid_path;

	valid_path = NULL;
	i = 0;
	while (split_path[i])
	{
		if (access(split_path[i], F_OK | X_OK) == 0)
			valid_path = split_path[i];
		i++;
	}
	return (valid_path);
}
