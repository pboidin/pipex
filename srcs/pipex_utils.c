/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piboidin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:59:55 by piboidin          #+#    #+#             */
/*   Updated: 2022/01/28 15:59:57 by piboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*path_dir;
	int		i;

	i = 0;
	while(ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		path_dir = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path_dir, cmd);
		free(path_dir);
		if (access(path, F_OK) == 0)
			return (path);
		i++;
	}
	return (0);
}

void	ft_error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

void	ft_execute(char *argv, char **envp)
{
	char **cmd;

	cmd = ft_split(argv, ' ');
	if (execve(ft_path(cmd[0], envp), cmd, envp) == -1)
		ft_error();
}

int		ft_opener(char *argv, int i)
{
	int	fd;

	fd = 0;
	if (i == 0)
		fd = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (i == 1)
		fd = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (i == 2)
		fd = open(argv, O_RDONLY, 0777);
	if (i == -1)
		ft_error();
	return (fd);
}

int		ft_get_next_line(char **line)
{
	char	c;
	char	*buf;
	int		i;
	int		j;

	i = 0;
	buf = (char *)malloc(8000000);
	if (!buf)
		return (-1);
	j = read(0, &c, 1);
	while (c != '\n' && c != '\0' && j)
	{
		if (c != '\n' && c != '\0')
			buf[i] = c;
		i++;
		j = read(0, &c, 1);
	}
	buf[i] = '\n';
	buf[i++] = '\0';
	*line = buf;
	free(buf);
	return (j);
}
