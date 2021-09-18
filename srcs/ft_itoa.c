/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:21:25 by oozsertt          #+#    #+#             */
/*   Updated: 2021/09/18 23:07:56 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static int	ft_get_size_nbr(long nbr)
{
	int	count;

	if (nbr < 0)
	{
		count = 1;
		nbr *= -1;
	}
	else
		count = 0;
	while (nbr >= 10)
	{
		nbr /= 10;
		count++;
	}
	count++;
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len_str;
	long	nbr;

	nbr = n;
	len_str = ft_get_size_nbr(nbr);
	str = (char *)malloc(sizeof(char) * (len_str + 1));
	if (str == NULL)
		return (NULL);
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	str[len_str] = '\0';
	len_str--;
	while (nbr >= 10)
	{
		str[len_str] = (nbr % 10) + '0';
		nbr /= 10;
		len_str--;
	}
	str[len_str] = nbr + '0';
	return (str);
}
