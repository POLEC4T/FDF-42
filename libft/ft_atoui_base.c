/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoui_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:44:45 by mniemaz           #+#    #+#             */
/*   Updated: 2025/02/13 16:46:33 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_atoui_base(const char *nptr, char *base)
{
	unsigned int	res;
	int				sign;
	int				i;

	res = 0;
	sign = 1;
	i = 0;
	while ((nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r')))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (pos_in_str(base, nptr[i]) != -1)
	{
		res = res * ft_strlen(base) + pos_in_str(base, nptr[i]);
		i++;
	}
	return (res * sign);
}
