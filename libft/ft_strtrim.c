/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:49:51 by mniemaz           #+#    #+#             */
/*   Updated: 2024/11/13 16:42:38 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_char_in_str(char c, const char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (1);
	return (0);
}

size_t	calc_res_size(char const *s1, char const *set)
{
	size_t	to_remove;
	int		i;

	i = -1;
	to_remove = 0;
	while (s1[++i] && is_char_in_str(s1[i], set))
		to_remove++;
	if (to_remove == ft_strlen(s1))
		return (0);
	i = ft_strlen(s1);
	while (s1[--i] && is_char_in_str(s1[i], set))
		to_remove++;
	return (ft_strlen(s1) - to_remove);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		i_s;
	int		i_res;
	int		res_size;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	res_size = calc_res_size(s1, set);
	res = malloc((res_size + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i_s = 0;
	while (s1[i_s] && is_char_in_str(s1[i_s], set))
		i_s++;
	i_res = 0;
	while (s1[i_s] && i_res < res_size)
		res[i_res++] = s1[i_s++];
	res[res_size] = '\0';
	return (res);
}
