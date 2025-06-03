/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheher <micheher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:39:32 by micheher          #+#    #+#             */
/*   Updated: 2025/06/03 12:42:28 by micheher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	void	*new_obj;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	tmp = NULL;
	while (lst != NULL)
	{
		new_obj = f(lst->content);
		new_list = ft_lstnew(new_obj);
		if (!new_list)
		{
			del(new_obj);
			ft_lstclear(&tmp, del);
		}
		ft_lstadd_back(&tmp, new_list);
		lst = lst->next;
	}
	return (tmp);
}
