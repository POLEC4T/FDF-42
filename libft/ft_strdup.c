/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:30:13 by mniemaz           #+#    #+#             */
/*   Updated: 2024/11/14 14:32:04 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	len;

	len = ft_strlen(s);
	copy = malloc((len + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, s, len + 1);
	return (copy);
}
