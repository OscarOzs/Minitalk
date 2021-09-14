/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 22:19:00 by oozsertt          #+#    #+#             */
/*   Updated: 2021/09/14 20:06:09 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <libc.h>

int	check_error(char *str, int ac)
{
	int	i;

	i = 0;
	if (ac != 3)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int main(int ac, char **av)
{
	int		pid;

	if (check_error(av[1], ac) == 0)
	{
		printf("invalid arguments\n");
		exit(EXIT_FAILURE);
	}
	pid = atoi(av[1]);
}