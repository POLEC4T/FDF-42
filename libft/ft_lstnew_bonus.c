/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:55:25 by mniemaz           #+#    #+#             */
/*   Updated: 2024/11/25 17:57:05 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elem_ptr;

	elem_ptr = malloc(sizeof(t_list));
	if (!elem_ptr)
		return (NULL);
	elem_ptr->content = content;
	elem_ptr->next = NULL;
	return (elem_ptr);
}
