/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 21:06:51 by oozsertt          #+#    #+#             */
/*   Updated: 2021/09/15 17:31:15 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <libc.h>

int		ft_atoi(const char *str);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

char	*convert_and_print(char *binary)
{
	char	*str;
	char	c;

	binary[7] = '\0';
	str = ft_convert_base(binary, "01", "0123456789");
	c = ft_atoi(str);
	write(1, &c, 1);
	return (str);
}

void	handler_bothsigusr(int signal)
{
	static int	i;
	static char	*binary;

	if (binary == NULL)
	{
		binary = (char *)malloc(sizeof(char) * (7 + 1));
		if (binary == NULL)
		{
			printf("malloc failed\n");
			exit(EXIT_FAILURE);
		}
	}
	if (signal == SIGUSR1)
	{
		binary[i] = '1';
		i++;
		usleep(100);
	}
	else if (signal == SIGUSR2)
	{
		binary[i] = '0';
		i++;
		usleep(100);
	}
	if (binary[6] == '0' || binary[6] == '1')
		binary = convert_and_print(binary);
}

void	get_signal()
{
	signal(SIGUSR1, handler_bothsigusr);
	signal(SIGUSR2, handler_bothsigusr);
}

int main()
{
	pid_t	pid;

	pid = getpid();
	printf("PID : %d\n", pid);
	get_signal();
	while (1)
		pause();
}
