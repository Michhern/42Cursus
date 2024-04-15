/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:42:58 by michhern          #+#    #+#             */
/*   Updated: 2024/03/15 12:06:24 by michhern         ###   ########.fr       */
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
/*
Esta función en C, `ft_lstadd_back`, se utiliza para agregar un nuevo nodo al
final de una lista enlazada. Aquí tienes una explicación paso a paso de lo que 
hace:

1. `void ft_lstadd_back(t_list **lst, t_list *new)`: Esto es la definición de
la función. Toma dos argumentos: `lst`, que es un puntero al puntero al primer
elemento de la lista, y `new`, que es un puntero al nuevo nodo que se va a
agregar.

2. `t_list *back;`: Declara un puntero `back` de tipo `t_list`, que se
utilizará para encontrar el último elemento de la lista.

3. `back = ft_lstlast(*lst);`: Llama a la función `ft_lstlast` para encontrar
el último elemento de la lista. Esta función debe estar definida en otro lugar
de tu código y devuelve un puntero al último nodo de la lista. Se le pasa como
argumento el contenido del puntero `lst` (el primer elemento de la lista).
El puntero `back` ahora apunta al último nodo de la lista.

4. `if (!back) *lst = new;`: Verifica si `back` es nulo. Si es así, significa
que la lista está vacía. En ese caso, asigna el puntero `new` al puntero `lst`,
lo que significa que `lst` ahora apunta al nuevo nodo. Esto asegura que el
primer elemento de la lista sea el nuevo nodo.

5. `else back->next = new;`: Si la lista no está vacía, significa que `back`
apunta al último nodo de la lista. Por lo tanto, establece el siguiente puntero
del nodo `back` para que apunte al nuevo nodo (`new`). Esto agrega el nuevo nodo
al final de la lista, ya que `back` apunta al último nodo y `back->next` es el
puntero al siguiente nodo después de `back`, que es el lugar donde se agrega el
nuevo nodo.

En resumen, `ft_lstadd_back` agrega el nodo `new` al final de la lista enlazada
apuntada por `lst`, ya sea creando una nueva lista si `lst` es nulo o agregando
el nodo al final de la lista existente si la lista ya contiene elementos.
*/