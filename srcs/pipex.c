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

void	ft_child_cmd(char **argv, int *fd, char **envp)
{
	int	infile;

	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
		ft_error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[0]);
	ft_execute(argv[2], envp);
}

void	ft_mother_cmd(char **argv, int *fd, char **envp)
{
	int	outfile;
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		ft_error();
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	ft_execute(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int 	pipefd[2];
	pid_t	cpid;
	
	if (argc != 5)
	{
		ft_putstr("\x1b[31mError : Wrong Arguments!!\n\e[0m");
		ft_putstr("Waiting : ./pipex file1 cmd1 cmd2 file2\n");
	}
	else
	{
		ft_putstr("\x1b[32mOK Let's go in the Fonction Pipex\n\e[0m");
		if (pipe(pipefd) == -1)
			ft_error();
		cpid = fork();
		if (cpid == -1)
			ft_error();
		if (cpid == 0)
			ft_child_cmd(argv, pipefd, envp);
		waitpid(cpid, NULL, 0);
		ft_mother_cmd(argv, pipefd, envp);
		close(pipefd[0]);
		close(pipefd[1]);
	}
	return (0);
}
