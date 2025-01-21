/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:01:09 by michhern          #+#    #+#             */
/*   Updated: 2024/10/31 10:38:58 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"

typedef struct s_stack_node
{
	long					nbr;
	int						index;
	int						push_cost;
	bool					above_median;
	bool					lower;
	struct s_stack_node		*target_node;
	struct s_stack_node		*next;
	struct s_stack_node		*prev;
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
void			init_nodes(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
void			current_index(t_stack_node *stack);
void			set_cheapest_cost(t_stack_node *stack);
void			prep_for_push(t_stack_node **stack, t_stack_node *top_node,
					char stack_name);
t_stack_node	*return_the_cheapest(t_stack_node *stack);

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
void			sort_stacks(t_stack_node **a, t_stack_node **b);
int				find_median(t_stack_node *array, int size);
int				calculate_median(t_stack_node *array, int size);
void			move_nodes(t_stack_node **a, t_stack_node **b);
void			sort_five(t_stack_node **a, t_stack_node **b);//prueba 30/10
void			rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *low_node); //agregado 30/10
void			reverse_rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *low_node); //agregado 30/10
void			mini_on_top(t_stack_node **a); //agregado 30/10
void			sort_stack_final(t_stack_node **a); //agregado 30/10

#endif
