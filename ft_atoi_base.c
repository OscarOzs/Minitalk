/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 14:43:11 by oozsertt          #+#    #+#             */
/*   Updated: 2021/09/14 20:34:03 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] <= 32 || base[i] > 126)
			return (0);
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_check_str(char *str, char *base)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	if (str[i] == '-')
	{
		i++;
		count++;
	}
	while (str[i] != '\0')
	{
		while (base[j] != '\0')
		{
			if (str[i] == base[j])
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	return (ft_strlen(str) == count ? 1 : 0);
}

int		ft_place_in_base(char c, char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (c == str[i])
			return (i);
		i++;
	}
	return (0);
}

int		ft_atoi_base(char *str, char *base)
{
	long	res;
	int		len_base;
	int		sign;
	int		i;

	res = 0;
	i = 0;
	sign = 1;
	len_base = ft_strlen(base);
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (ft_check_base(base) == 1 && ft_check_str(str, base) == 1)
	{
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				sign = -1;
			i++;
		}
		while (str[i] != '\0')
		{
			res = res * ft_strlen(base) + ft_place_in_base(str[i], base);
			i++;
		}
	}
	return (res * sign);
}
