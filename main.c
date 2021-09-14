/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 20:12:03 by oozsertt          #+#    #+#             */
/*   Updated: 2021/09/14 20:34:17 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <libc.h>

// char			*ft_itoa(int n);
// char			*ft_convert_base(char *nbr, char *base_from, char *base_to);

// int	ft_strlen(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 		i++;
// 	return (i);
// }

// char	*str_space_sep(char *s)
// {
// 	char *str;
// 	int i;
// 	int	j;
// 	int	str_len;

// 	str_len = (ft_strlen(s) * 2);
// 	str = (char *)malloc(sizeof(char) * (str_len + 1));
// 	if (str == NULL)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (s[i] != '\0')
// 	{
// 		str[j] = s[i];
// 		j++;
// 		str[j] = ' ';
// 		j++;
// 		i++;
// 	}
// 	return (str);
// }

// int main(int ac, char **av)
// {
// 	char	*nbr;
// 	char	*binary;

// 	if (ac != 2)
// 	{
// 		printf("Error\n");
// 		return(0);
// 	}
// 	int i = 0;
// 	while (av[1][i] != '\0')
// 	{
// 		nbr = ft_itoa(av[1][i]);
// 		binary = ft_convert_base(nbr, "0123456789", "01");
// 		printf("%s\n", binary);
// 		i++;
// 	}
// }

int		ft_atoi_base(char *str, char *base);

int main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("error\n");
		return (0);
	}
	printf("%d\n", ft_atoi_base(av[1], "0123456789"));
}