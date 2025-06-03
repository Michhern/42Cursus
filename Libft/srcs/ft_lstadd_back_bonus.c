/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheher <micheher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:26:26 by micheher          #+#    #+#             */
/*   Updated: 2025/06/03 13:31:32 by micheher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*back;

	back = ft_lstlast(*lst);
	if (!back)
		*lst = new;
	else
		back->next = new;
}

/*int	main(void)
{
	//Crear una lista enlazada vacia
	t_list	*list = NULL;
	//Crear un nuevo node
	t_list	*new_node = malloc(sizeof(t_list));
	new_node->content = "Nuevo node";
	new_node->next = NULL;
	//Agregar eel  nuevo node al final de la lista;
	ft_lstadd_back(&list, new_node);
	//Imprimir el contenido del ultimo node de la lista
	t_list	*last_node = ft_lstlast(list);
	if (last_node != NULL)
	{
		printf("Contenido del ultimo node: %s\n", (char *)last_node->content);
	}
	else
	{
		printf("La lista esta vacía.\n");
	}
	free(new_node);
	return (0);
}*/