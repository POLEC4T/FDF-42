/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:53:33 by mniemaz           #+#    #+#             */
/*   Updated: 2024/11/13 16:05:30 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_d;
	const unsigned char	*ptr_s;

	if (!dest && !src)
		return (NULL);
	ptr_d = dest;
	ptr_s = src;
	while (n)
	{
		*ptr_d = *ptr_s;
		ptr_d++;
		ptr_s++;
		n--;
	}
	return (dest);
}
