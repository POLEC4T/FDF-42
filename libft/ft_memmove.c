/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:10:13 by mniemaz           #+#    #+#             */
/*   Updated: 2024/11/08 17:42:35 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*p_d;
	const unsigned char	*p_s;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	p_d = dest;
	p_s = src;
	i = 0;
	if (dest > src)
		while (n--)
			p_d[n] = p_s[n];
	else
	{
		while (i < n)
		{
			p_d[i] = p_s[i];
			i++;
		}
	}
	return (dest);
}
