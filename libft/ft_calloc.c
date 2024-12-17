/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:21:28 by mniemaz           #+#    #+#             */
/*   Updated: 2024/11/14 14:28:27 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;

	if (size != 0 && nmemb > __SIZE_MAX__ / size)
		return (NULL);
	mem = malloc(nmemb * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, nmemb * size);
	return (mem);
}

// #include <stdio.h>
// int	main(void)
// {
// 	// char *s = calloc(3, -1);
// 	char *s = ft_calloc(0, 0);
// 	printf("%p\n", s);
// 	return (0);
// }