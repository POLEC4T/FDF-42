/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:48:10 by mniemaz           #+#    #+#             */
/*   Updated: 2024/11/07 18:49:14 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	size_t	len;

	len = ft_strlen(s);
	i = (int)len + 1;
	while (--i >= 0)
		if (s[i] == (char)c)
			return ((char *)(s + i));
	return (NULL);
}
