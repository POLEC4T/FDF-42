/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:44:45 by mniemaz           #+#    #+#             */
/*   Updated: 2025/02/13 16:57:16 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int				i;
	int				sign;
	unsigned long	res;
	unsigned long	limit;
	int				to_add;

	i = 0;
	sign = 1;
	res = 0;
	limit = (unsigned long)(__LONG_MAX__ / 10);
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			sign = -1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		to_add = nptr[i++] - '0';
		if (sign == 1 && (res > limit || (res == limit && to_add > 7)))
			return (-1);
		else if (sign == -1 && (res > limit || (res == limit && to_add > 8)))
			return (0);
		res = res * 10 + to_add;
	}
	return (res * sign);
}
