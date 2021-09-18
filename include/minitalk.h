/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 23:28:31 by oozsertt          #+#    #+#             */
/*   Updated: 2021/09/18 23:22:20 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_atoi_base(char *str, char *base);
int		ft_atoi(const char *str);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
char	*ft_itoa(int n);
void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlen(const	char *s);

#endif