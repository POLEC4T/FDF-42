/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_digitbase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:38:07 by mniemaz           #+#    #+#             */
/*   Updated: 2025/02/13 16:46:52 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit_base(char c, int base)
{
	if (base <= 10)
		return (c >= '0' && c < '0' + base);
	return (ft_isdigit(c) || (c >= 'a' && c < 'a' + base - 10) || (c >= 'A'
			&& c < 'A' + base - 10));
}
