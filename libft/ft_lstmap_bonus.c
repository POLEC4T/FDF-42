/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:07:35 by niemazm           #+#    #+#             */
/*   Updated: 2024/11/08 17:40:10 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_new;
	t_list	*lst_tmp;
	void	*tmp;

	if (!lst || !f)
		return (NULL);
	lst_new = NULL;
	while (lst)
	{
		tmp = f(lst->content);
		lst_tmp = ft_lstnew(tmp);
		if (!lst_tmp)
		{
			del(tmp);
			ft_lstclear(&lst_new, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_new, lst_tmp);
		lst = lst->next;
	}
	return (lst_new);
}
