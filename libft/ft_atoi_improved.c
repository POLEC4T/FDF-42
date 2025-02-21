/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_improved.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:44:45 by mniemaz           #+#    #+#             */
/*   Updated: 2025/02/21 10:27:14 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_is_out_of_range(unsigned long res, int sign, int *is_out_of_range)
{
	if (sign == 1 && res > (unsigned long)INT_MAX)
	{
		*is_out_of_range = 1;
		return (1);
	}
	if (sign == -1 && res > (unsigned long)INT_MAX + 1)
	{
		*is_out_of_range = 1;
		return (1);
	}
	return (0);
}

int	ft_atoi_improved(const char *nptr, int *is_out_of_range)
{
	int				i;
	int				sign;
	unsigned long	res;

	i = 0;
	sign = 1;
	res = 0;
	*is_out_of_range = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			sign = -1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i++] - '0';
		if (ft_is_out_of_range(res, sign, is_out_of_range))
			return (0);
	}
	return (res * sign);
}
