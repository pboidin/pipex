#include "pipex.h"

void	ft_child(char *argv, char **envp)
{
	int		fd[2];
	pid_t	cpid;

	if (pipe(fd) == -1)
		ft_error();
	cpid = fork();
	if (cpid == -1)
		ft_error();
	if (cpid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		ft_execute(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(cpid, NULL, 0);
	}
}

void	ft_here_doc(char *lim, int argc)
{
	char	*line;
	int		fd[2];
	pid_t	read;

	if (argc < 6)
		ft_error();
	if (pipe(fd) == -1)
		ft_error();
	read = fork();
	if (read == 0)
	{
		close (fd[0]);
		while (ft_get_next_line(&line))
		{
			if (ft_strncmp(line, lim, ft_strlen(lim)) == 0)
				exit(EXIT_SUCCESS);
			write(fd[1], line, ft_strlen(line));
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

int main(int argc, char **argv, char **envp)
{
	int	i;
	int	infile;
	int	outfile;

	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			i = 3;
			outfile = ft_opener(argv[argc - 1], 0);
			ft_here_doc(argv[2], argc);
		}
		else
		{
			i = 2;
			outfile = ft_opener(argv[argc - 1], 1);
			infile = ft_opener(argv[1], 2);
			dup2(infile, STDIN_FILENO);
		}
		while (i < (argc - 2))
			ft_child(argv[i++], envp);
		dup2(outfile, STDOUT_FILENO);
		ft_execute(argv[argc - 2], envp);
	}
	printf("FUCK");
}
