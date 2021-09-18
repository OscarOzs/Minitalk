/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 22:19:00 by oozsertt          #+#    #+#             */
/*   Updated: 2021/09/18 22:47:40 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

static int	check_error(char *str, int ac)
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

static void	send_signal(char *binary, pid_t pid)
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

int	main(int ac, char **av)
{
	char	*nbr;
	char	*binary;
	int		i;
	pid_t	server_pid;

	if (check_error(av[1], ac) == 0)
	{
		printf("invalid arguments\n");
		exit(EXIT_FAILURE);
	}
	server_pid = atoi(av[1]);
	i = 0;
	while (av[2][i] != '\0')
	{
		nbr = ft_itoa(av[2][i]);
		binary = ft_convert_base(nbr, "0123456789", "01");
		send_signal(binary, server_pid);
		free(nbr);
		free(binary);
		i++;
	}
	exit(EXIT_SUCCESS);
}
