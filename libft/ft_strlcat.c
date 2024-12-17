/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:16:33 by mniemaz           #+#    #+#             */
/*   Updated: 2024/11/14 14:24:14 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstlen;

	dstlen = ft_strlen(dst);
	i = 0;
	while (src[i] && i + dstlen + 1 < size)
	{
		dst[i + dstlen] = src[i];
		i++;
	}
	dst[i + dstlen] = '\0';
	if (size < dstlen)
		dstlen = size;
	return (ft_strlen(src) + dstlen);
}

// int main(void)
// {

// 	char dest[14] = 'a';
//     ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 15));
//     write(1, "\n", 1);
//     write(1, dest, 15);
// }