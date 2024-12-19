/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:47:35 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/19 18:12:07 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*copy;
	size_t	len;

	len = ft_strlen(s);
	if (n < len)
		len = n;
	copy = malloc((len + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, s, len + 1);
	return (copy);
}

int	ft_strchr_idx(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
		if (*(unsigned char *)(s + i) == (char)c)
			return (i);
	return (-1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1 && s2)
		return (ft_strndup((const char *)s2, ft_strlen((const char *)s2)));
	if (s1 && !s2)
		return (ft_strndup((const char *)s1, ft_strlen((const char *)s1)));
	i = -1;
	res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (s1[++i])
		res[i] = s1[i];
	j = -1;
	while (s2[++j])
		res[i + j] = s2[j];
	res[i + j] = '\0';
	return (res);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t sz)
{
	size_t	i;

	i = 0;
	if (sz == 0)
		return (ft_strlen(src));
	while (src[i] && i + 1 < sz)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
