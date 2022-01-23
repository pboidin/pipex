/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piboidin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:23:44 by piboidin          #+#    #+#             */
/*   Updated: 2022/01/21 12:03:32 by piboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

char	*ft_strjoin(char const *s1, char const *s2);
char    *ft_strnstr(const char *big, const char *little, size_t n);

char	**ft_split(char const *s, char c);

void	ft_error(void);
void	ft_execute(char *argv, char **envp);
void	ft_putstr(char *str);

#endif
