/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piboidin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 10:47:13 by piboidin          #+#    #+#             */
/*   Updated: 2022/01/21 12:07:43 by piboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	int 	pipefd[2];
	pid_f	cpid;
	(void)argv;
	
	if (argc == 5)
	{
		ft_putstr("\x1b[32mOK Let's go in the Fonction Pipex\n\e[0m");
		if (pipe(pipefd) == -1)
		{
			perror("Pipe");
			exit();
		}
		cpid= fork();
		if (cpid == -1)
		{
			perror("fork");
			exit();
		}
	}
	else
	{
		ft_putstr("\x1b[31mError : Wrong Arguments !!\n\e[0m");
		ft_putstr("Waiting somethinig just like this : ./pipex file1 cmd1 cmd2 file2\n");
	}
}
