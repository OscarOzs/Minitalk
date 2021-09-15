/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:57:41 by oozsertt          #+#    #+#             */
/*   Updated: 2021/09/15 16:53:53 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);

static int	get_nb_len(int nbr, char *base)
{
	int	len;
	int	base_len;

	base_len = 0;
	while (base[base_len] != '\0')
		base_len++;
	len = 0;
	while (nbr >= base_len)
	{
		len++;
		nbr /= base_len;
	}
	len++;
	return (len);
}

char	*fill_res(char *res, int nbr, char *base, int nb_len)
{
	int	base_len;
	int	i;

	base_len = 0;
	while (base[base_len] != '\0')
		base_len++;
	i = 0;
	if (nbr < 0)
	{
		res[i] = '-';
		nbr *= -1;
	}
	while (nbr >= base_len)
	{
		res[nb_len] = base[nbr % base_len];
		nbr /= base_len;
		nb_len--;
	}
	res[nb_len] = base[nbr % base_len];
	nbr /= base_len;
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*res;
	int		nb;
	int		nbr_len;

	if (nbr == NULL || base_from == NULL || base_to == NULL)
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	nbr_len = get_nb_len(nb, base_to);
	res = (char *)malloc(sizeof(char) * (nbr_len + 1));
	if (res == NULL)
		return (NULL);
	res[nbr_len] = '\0';
	res = fill_res(res, nb, base_to, (nbr_len - 1));
	return (res);
}
