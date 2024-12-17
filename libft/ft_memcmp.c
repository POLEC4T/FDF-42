/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:28:52 by mniemaz           #+#    #+#             */
/*   Updated: 2024/11/07 15:37:07 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i + 1 < n
		&& ((unsigned char *)(s1))[i] == ((unsigned char *)(s2))[i])
		i++;
	return (((unsigned char *)(s1))[i] - ((unsigned char *)(s2))[i]);
}
