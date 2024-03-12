/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:42:58 by michhern          #+#    #+#             */
/*   Updated: 2024/02/15 16:13:49 by michhern         ###   ########.fr       */
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
