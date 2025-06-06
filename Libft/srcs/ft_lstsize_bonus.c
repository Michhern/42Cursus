/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheher <micheher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:17:32 by micheher          #+#    #+#             */
/*   Updated: 2025/06/03 12:20:45 by micheher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*str;
	int		i;

	str = lst;
	i = 0;
	while (str != NULL)
	{
		str = str->next;
		i++;
	}
	return (i);
}

/*int main(void)
{
	//Crear una lista enlazada con tres nodes
	t_list	*node1 = malloc(sizeof(t_list));
	t_list	*node2 = malloc(sizeof(t_list));
	t_list	*node3 = malloc(sizeof(t_list));
	//Inicializar en contenido de los nodes
	int	content1 = 1;
	int	content2 = 2;
	int	content3 = 3;
	
	node1->content = &content1;
	node2->content = &content2;
	node3->content = &content3;
	//Enlazar los nodes
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	//calcular el tamaño de la lista
	int	size = ft_lstsize(node1);
	//Imprimir el tamaño de la lista
	printf("El tamaño de la lsit es: %d\n", size);
	//Limpiar memoria asignada para los nodes
	free(node1);
	free(node2);
	free(node3);
	return (0);
}*/