/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheher <micheher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:21:32 by micheher          #+#    #+#             */
/*   Updated: 2025/06/03 12:30:32 by micheher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

/*int	main(void)
{
	//Crear una lista enlazada con tres nodes
	t_list	*node1 = malloc(sizeof(t_list));
	t_list	*node2 = malloc(sizeof(t_list));
	t_list	*node3 = malloc(sizeof(t_list));
	//Inicializar en contenido de los nodes
	int		content1 = 31313;
	int		content2 = 44545;
	int		content3 = 45684511;

	node1->content = &content1;
	node2->content = &content2;
	node3->content = &content3;
	//Enlazar los nodes
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	//Encontrar el ultmo nodo de la lista
	t_list	*last_node = ft_lstlast(node1);
	//Imprimir el contenido del ultimo nodo
	printf("El contenido del ultimo nodo es: %d\n", *(int *)last_node->content);
	//Liberar memoria asignada para los nodes
	free(node1);
	free(node2);
	free(node3);
	return (0);
}*/