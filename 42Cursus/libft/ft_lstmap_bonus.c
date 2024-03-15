/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:06:52 by michhern          #+#    #+#             */
/*   Updated: 2024/02/15 16:15:02 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_obj;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	tmp = NULL;
	while (lst != NULL)
	{
		new_obj = f(lst->content);
		new_list = ft_lstnew(f(lst->content));
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
//Crear main y repasar la funcion 
