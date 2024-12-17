/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:16:17 by mniemaz           #+#    #+#             */
/*   Updated: 2024/11/14 14:31:39 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p_s;
	size_t				i;

	p_s = s;
	i = -1;
	while (++i < n)
		if ((unsigned char)(p_s[i]) == (unsigned char)(c))
			return ((void *)(s + i));
	return (NULL);
}
