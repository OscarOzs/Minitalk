/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 22:19:00 by oozsertt          #+#    #+#             */
/*   Updated: 2021/09/15 18:18:41 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <libc.h>

char		*ft_itoa(int n);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

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

void	send_signal(char *binary, pid_t pid)
{
	int	i;

	i = 0;
	while (binary[i] != '\0')
	{
		if (binary[i] == '1')
		{
			kill(pid, SIGUSR1);
			usleep(100);
		}
		else if (binary[i] == '0')
		{
			kill(pid, SIGUSR2);
			usleep(100);
		}
		i++;
	}
}

int main(int ac, char **av)
{
	pid_t		pid;

	if (check_error(av[1], ac) == 0)
	{
		printf("invalid arguments\n");
		exit(EXIT_FAILURE);
	}
	pid = atoi(av[1]);
	char	*nbr;
	char	*binary;
	int i = 0;

	while (av[2][i] != '\0')
	{
		nbr = ft_itoa(av[2][i]);
		binary = ft_convert_base(nbr, "0123456789", "01");
		send_signal(binary, pid);
		i++;
	}
}