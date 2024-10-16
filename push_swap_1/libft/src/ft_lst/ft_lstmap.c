/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:31:54 by michhern          #+#    #+#             */
/*   Updated: 2024/07/23 17:35:05 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

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
