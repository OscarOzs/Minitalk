/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:21:25 by oozsertt          #+#    #+#             */
/*   Updated: 2021/09/14 18:15:36 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_get_size_nbr(long nbr)
{
	int count;

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

char		*ft_itoa(int n)
{
	char	*str;
	int		len_str;
	long	nbr;

	nbr = n;
	len_str = ft_get_size_nbr(nbr);
	if (nbr < 0)
	{
		if ((str = (char*)malloc(sizeof(char) * len_str + 1)) == NULL)
			return (NULL);
		str[0] = '-';
		nbr *= -1;
	}
	else if ((str = (char*)malloc(sizeof(char) * len_str + 1)) == NULL)
		return (NULL);
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
