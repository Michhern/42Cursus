/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:01:09 by michhern          #+#    #+#             */
/*   Updated: 2024/09/24 17:52:53 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				lower;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

//handle error
int				syntax(char *str);
int				duplicate(t_stack_node *a, int n);
void			free_stack(t_stack_node **stack);
void			free_errors(t_stack_node **a, char *str);
//Stack initiation
void			init_stack_a(t_stack_node **a, char **av);
char			**split(char *s, char c);

//Nodes initiation
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
void			current_index(t_stack_node *stack);
void			mark_lower_cost(t_stack_node *stack);
void			prep_for_push(t_stack_node **stack, t_stack_node *top_node,
					char stack_name);
t_stack_node	*get_the_lower(t_stack_node *stack);

//Stack utils
int				stack_len(t_stack_node *stack);
int				calculate_push_cost(t_stack_node *node_b, t_stack_node *a,
					int len_b, int len_a);
bool			stack_sorted(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*find_bigger_close(t_stack_node *a, t_stack_node *b);
t_stack_node	*find_target_node(t_stack_node *a, t_stack_node *b);
t_stack_node	*push_cost_node(t_stack_node *b, t_stack_node *a,
					int len_b, int len_a);

//Comands
void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);
void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **b, t_stack_node **a, bool print);

//Algorithms
void			sort_three(t_stack_node **a);
void			sort_stacks(t_stack_node **a, t_stack_node **b, int median);
void			sort_array(int *arr, int len);
int				find_median(t_stack_node *arr, int size);
int				calculate_median(t_stack_node *array, int size);
void			move_best_node_and_target_on_top(t_stack_node *a, t_stack_node *b);

int				t_stack_node_lstsize(t_stack_node *lst);


#endif