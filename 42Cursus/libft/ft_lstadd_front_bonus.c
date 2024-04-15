/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:22:05 by michhern          #+#    #+#             */
/*   Updated: 2024/03/13 13:45:29 by michhern         ###   ########.fr       */
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
/*
Estas dos funciones trabajan juntas para crear y agregar un nuevo nodo al 
frente de una lista enlazada. Aquí está la explicación de cada una:

1. `t_list *ft_lstnew(void *content)`: Esta función crea un nuevo nodo
para una lista enlazada. Toma un puntero `content` como argumento que
apunta al contenido que se almacenará en el nuevo nodo. Aquí está el
detalle de lo que hace:

   - `t_list *data;`: Declara un puntero `data` de tipo `t_list`, que
   se utilizará para apuntar al nuevo nodo que se creará.

   - `data = malloc(sizeof(t_list));`: Asigna memoria para el nuevo nodo
   utilizando `malloc`. `sizeof(t_list)` devuelve el tamaño en bytes de
   la estructura `t_list`. Si no se puede asignar memoria (por falta de
   espacio o algún otro problema), la función devuelve `NULL`.

   - `if (!data) return (NULL);`: Verifica si la asignación de memoria
   fue exitosa. Si no lo fue, la función devuelve `NULL`.
   - `data->content = content;`: Asigna el contenido proporcionado al
   campo `content` del nuevo nodo.

   - `data->next = NULL;`: Establece el puntero `next` del nuevo nodo
   como `NULL`, ya que inicialmente no hay ningún nodo siguiente.

   - `return (data);`: Devuelve un puntero al nuevo nodo creado.

2. `void ft_lstadd_front(t_list **lst, t_list *new)`: Esta función agrega
un nuevo nodo al frente de una lista enlazada. Toma dos argumentos:
un puntero al puntero al primer elemento de la lista (`lst`) y un puntero
al nuevo nodo que se va a agregar (`new`). Aquí está el detalle de lo
que hace:

   - `new->next = *lst;`: Establece el puntero `next` del nuevo nodo para
   que apunte al primer elemento actual de la lista, haciendo que el nuevo
   nodo apunte al primer elemento de la lista.
   - `*lst = new;`: Actualiza el puntero al primer elemento de la lista
   (`lst`) para que apunte al nuevo nodo. Esto significa que el nuevo nodo
   ahora se convierte en el primer elemento de la lista.
   
En resumen, `ft_lstnew` crea un nuevo nodo con el contenido proporcionado,
mientras que `ft_lstadd_front` agrega este nuevo nodo al frente de la
lista enlazada, convirtiéndolo en el nuevo primer elemento de la lista.
*/