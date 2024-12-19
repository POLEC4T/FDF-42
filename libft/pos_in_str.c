/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_in_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:25:51 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/19 19:11:24 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @returns the index of c in str, -1 else
 */
int pos_in_str(char *str, char c)
{
    int i;

    i = 0;
    while(str[i])
    {
        if (str[i] == c)
            return (i);
        i++;
    }
    return (-1);
}