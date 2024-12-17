/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:05:35 by niemazm           #+#    #+#             */
/*   Updated: 2024/11/14 11:22:27 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/* int main()
{
	t_list	*a;
	t_list	*b;

	a = ft_lstnew("slay");
	b = ft_lstnew("slow");

	ft_lstadd_back(&a, b);
	ft_lstiter(a, NULL);
} */