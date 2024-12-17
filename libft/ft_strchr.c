/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:37:56 by mniemaz           #+#    #+#             */
/*   Updated: 2024/11/14 14:32:44 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
		if (*(unsigned char *)(s + i) == (char)c)
			break ;
	if (*(unsigned char *)(s + i) == (char)c)
		return ((char *)(s + i));
	return (NULL);
}
