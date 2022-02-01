/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piboidin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:52:08 by piboidin          #+#    #+#             */
/*   Updated: 2022/02/01 11:40:24 by piboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

char	*ft_path(char *cmd, char **envp);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *big, const char *little, size_t n);

char	**ft_split(char const *s, char c);

int		ft_get_next_line(char **line);
int		ft_opener(char *argv, int i);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

size_t	ft_strlen(const char *s);

void	ft_error(void);
void	ft_execute(char *argv, char **envp);
void	ft_here_doc(char *lim, int argc);
void	ft_putstr_fd(char *s, int fd);

#endif
