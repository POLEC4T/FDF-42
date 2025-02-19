/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:11:36 by mniemaz           #+#    #+#             */
/*   Updated: 2025/02/17 17:58:33 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_str_tab(char **tab, int limit)
{
	int	i;

	i = -1;
	while (++i < limit)
		free(tab[i]);
	free(tab);
}

int	calc_nb_words(char const *s, char *delim)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		if ((pos_in_str(delim, s[i])) == -1 && ((pos_in_str(delim, s[i
							+ 1])) >= 0 || s[i + 1] == '\0'))
			counter++;
		i++;
	}
	return (counter);
}

char	*fill_word(char *word, char const *s, char *delim)
{
	int	i;

	i = -1;
	while (s[++i] && (pos_in_str(delim, s[i])) == -1)
		word[i] = s[i];
	word[i] = '\0';
	return (word);
}

int	alloc_n_write(char **res, char const *s, char *delim)
{
	int	i;
	int	old_i;
	int	i_res;

	i = 0;
	i_res = 0;
	while (s[i])
	{
		while (s[i] && (pos_in_str(delim, s[i])) >= 0)
			i++;
		old_i = i;
		while (s[i] && pos_in_str(delim, s[i]) == -1)
			i++;
		if (old_i < i)
		{
			res[i_res] = malloc((i - old_i + 1) * sizeof(char));
			if (!res[i_res])
				return (i_res);
			fill_word(res[i_res], s + old_i, delim);
			i_res++;
		}
	}
	return (-1);
}

char	**ft_split(char const *s, char *delim)
{
	char	**res;
	int		nb_words;
	int		i_alloc_res;

	if (!s)
		return (NULL);
	nb_words = calc_nb_words(s, delim);
	res = malloc((nb_words + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i_alloc_res = alloc_n_write(res, s, delim);
	if (i_alloc_res != -1)
	{
		free_str_tab(res, i_alloc_res);
		return (NULL);
	}
	res[nb_words] = NULL;
	return (res);
}