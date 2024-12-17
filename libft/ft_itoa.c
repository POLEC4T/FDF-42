/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:18:19 by niemazm           #+#    #+#             */
/*   Updated: 2024/11/07 17:31:39 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	calc_str_size(int n)
{
	size_t	counter;

	counter = 0;
	if (n == 0 || n < 0)
		counter++;
	while (n > 0 || n < 0)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

void	ft_itoa_rec(unsigned int n, char *res)
{
	size_t	i_res;

	i_res = ft_strlen(res);
	if (n < 10)
	{
		res[i_res++] = n + 48;
		res[i_res++] = '\0';
	}
	else
	{
		ft_itoa_rec(n / 10, res);
		ft_itoa_rec(n % 10, res);
	}
}

char	*ft_itoa(int n)
{
	size_t			str_size;
	char			*res;
	unsigned int	u_n;

	str_size = calc_str_size(n);
	res = malloc((str_size + 1) * sizeof(char));
	if (!res)
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		res[1] = '\0';
		u_n = -n;
	}
	else
	{
		res[0] = '\0';
		u_n = n;
	}
	ft_itoa_rec(u_n, res);
	res[str_size] = '\0';
	return (res);
}
