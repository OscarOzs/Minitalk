/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 15:07:18 by oozsertt          #+#    #+#             */
/*   Updated: 2021/09/18 23:08:11 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*tempfill;

	i = 0;
	tempfill = b;
	while (i < len)
	{
		*tempfill = c;
		i++;
		tempfill++;
	}
	return (b);
}
