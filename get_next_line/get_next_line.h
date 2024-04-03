/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:08:06 by michhern          #+#    #+#             */
/*   Updated: 2024/04/03 13:47:40 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	char			*str_buf;
	struct s_list	*next;	
}					t_list;

int		found_newline(t_list *list);
t_list	*find_last_node(t_list *list);
char	*get_a_line(t_list *list);
void	str_cpy(t_list *list, char *str);
int		len_to_newline(t_list *list);
void	manage_list(t_list **list);
char	*get_next_line(int fd);
void	free_malloc(t_list **list, t_list *free_node, char *buf);
void	make_list(t_list **list, int fd);
#endif