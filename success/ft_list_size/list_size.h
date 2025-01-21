/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_size.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:55:38 by michhern          #+#    #+#             */
/*   Updated: 2025/01/09 13:00:47 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_SIZE_H
# define LIST_SIZE_H

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

#endif