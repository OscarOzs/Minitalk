/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 21:06:51 by oozsertt          #+#    #+#             */
/*   Updated: 2021/09/21 19:38:59 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

static void	convert_and_print(char *binary)
{
	char	*str;
	char	c;

	str = ft_convert_base(binary, "01", "0123456789");
	if (str == NULL)
	{
		printf("malloc failed\n");
		exit(EXIT_FAILURE);
	}
	c = ft_atoi(str);
	write(1, &c, 1);
	ft_memset(binary, '\0', 8);
	free(str);
}

static void	handler(int signal)
{
	static int	i;
	static char	binary[8];

	if (signal == SIGUSR1)
	{
		binary[i] = '1';
		i++;
	}
	if (signal == SIGUSR2)
	{
		binary[i] = '0';
		i++;
	}
	if (i == 7)
	{
		convert_and_print(binary);
		i = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("PID : %d\n", pid);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
}
