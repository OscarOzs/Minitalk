/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_fullbinary.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:08:07 by oozsertt          #+#    #+#             */
/*   Updated: 2021/09/21 17:13:58 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int		ft_atoi(const char *str);
void	*ft_memset(void *b, int c, size_t len);

static char	*fill_res(char *res, char *binary, int nb)
{
	int	i;

	i = 6;
	while (nb >= 2)
	{
		res[i] = binary[nb % 2];
		nb /= 2;
		i--;
	}
	res[i] = binary[nb % 2];
	i--;
	while (i >= 0)
	{
		res[i] = '0';
		i--;
	}
	return (res);
}

char	*ft_convert_fullbinary(char *nbr, char *decimal, char *binary)
{
	char	*res;
	int		nb;

	if (nbr == NULL || decimal == NULL || binary == NULL)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (7 + 1));
	res[7] = '\0';
	nb = ft_atoi(nbr);
	res = fill_res(res, binary, nb);
	return (res);
}
