/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_envp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:27:43 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/03/12 20:21:14 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*check_envp(char **envp)
{
	int	i;

	i = 0;
	if (!envp)
		return (0);

	while(envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			return (envp[i]);
		}
		i++;
	}
	return (NULL);
}
