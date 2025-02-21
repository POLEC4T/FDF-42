/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:58:55 by mniemaz           #+#    #+#             */
/*   Updated: 2025/02/21 14:33:29 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/**
 * @returns the the number of strs in strtab
 * @example ["123", "123", "abc"] => 3
 */
int	strtab_len(char **strtab)
{
	int	i;

	i = 0;
	while (strtab[i])
		i++;
	return (i);
}

/**
 * @returns the the number of valid elems in strtab
 * @example ["123", "123", "5,0x123", "abc", ] => 3
 */
int	strtab_len_valid_elems(char **strtab)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (strtab[i])
	{
		if (is_element_valid(strtab[i]))
			count++;
		i++;
	}
	return (count);
}

/**
 * @returns 1 if to_find is at the end of str, 0 otherwise
 */
int	end_with(char *str, char *to_find)
{
	int	i;
	int	j;

	i = ft_strlen(str) - 1;
	j = ft_strlen(to_find) - 1;
	while (j >= 0)
	{
		if (str[i] != to_find[j])
			return (0);
		i--;
		j--;
	}
	return (1);
}
