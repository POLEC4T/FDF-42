/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:27:14 by niemazm           #+#    #+#             */
/*   Updated: 2025/02/13 16:47:31 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	unsigned int	u_n;
	int				counter;

	counter = 0;
	if (n < 0)
	{
		counter += ft_putchar_fd('-', fd);
		u_n = -n;
	}
	else
		u_n = n;
	if (u_n < 10)
		return (counter + ft_putchar_fd(u_n + 48, fd));
	else
	{
		counter += ft_putnbr_fd(u_n / 10, fd);
		return (counter + ft_putnbr_fd(u_n % 10, fd));
	}
}
