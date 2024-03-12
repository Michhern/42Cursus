/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:22:05 by michhern          #+#    #+#             */
/*   Updated: 2024/02/14 14:12:56 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*t_list	*ft_lstnew(void *content)
{
	t_list	*data;

	data = malloc(sizeof(t_list));
	if (!data)
		return (NULL);
	data->content = content;
	data->next = NULL;
	return (data);
}*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/*int	main(void)
{
	t_list	*node1 = ft_lstnew("Node 1");
	if (node1 == NULL)
	{
		printf("Error al crear el Node 1.\n");
		return (1);
	}
	t_list	*list = node1;
	t_list	*node2 = ft_lstnew("Node 2");
	if (node2 == NULL )
	{
		printf("Error al crear el Node 2.\n");
		free (node1);
		return (1);
	}
	ft_lstadd_front(&list, node2);
	printf("Lista despues de agregar el Node 2 al frente: \n");
	t_list	*current = list;
	while (current != NULL)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	free(node1);
	free(node2);
	return (0);
}*/
