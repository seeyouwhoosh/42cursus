/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:15:12 by xwu               #+#    #+#             */
/*   Updated: 2025/04/19 20:47:48 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "ft_printf.h"

/* LIST FUNCTIONS THAT ARE NOT INCLUDED IN THE LIBFT */

/* Check whether there are repeated ints in a linked list */
int		lstrepsint(t_list *lst);

/* Check whether the linked list of ints is sorted */
int		lstsortedsint(t_list *lst);

/* Print the linked list according to the format specified */
void	lstprint(t_list *lst, char format);

/* Get the minimum in the linked list */
int		ft_minint(t_list *lst);

/* Get the maximum in the linked list */
int		ft_maxint(t_list *lst);

/* OPERATIONS */

void	ft_sa(t_list *lst);

void	ft_pa(t_list **a, t_list **b);

void	ft_ra(t_list **lst);

void	ft_rra(t_list **lst);

void	rotate_a(t_list **a, int cost_a);

void	ft_sb(t_list *lst);

void	ft_pb(t_list **a, t_list **b);

void	ft_rb(t_list **lst);

void	ft_rrb(t_list **lst);

void	rotate_b(t_list **b, int cost_b);

void	ft_ss(t_list *a, t_list *b);

void	ft_rr(t_list **a, t_list **b);

void	ft_rrr(t_list **a, t_list **b);

void	rotate_ab(t_list **a, int cost_a, t_list **b, int cost_b);

/* Calculates the minimum steps to the top of the stack,
if it's negative, use reverse rotate */
int		cost_to_top(t_list *l, int n);

/* Calculates the total cost of moving from one stack to another */
int		op_cost(t_list *a, t_list *b, int n);

/* Calculates the minimun steps to the target position in the stack orderly */
int		target_pos(t_list *b, int n);

/* Get the index in which the int n is in */
int		ft_index(t_list *l, int n);

/* MATHEMATICAL FUNCTIONS */

int		ft_abs(int x);

int		ft_max(int a, int b);

int		ft_min(int a, int b);

int		ft_power(int base, int exp);

int		is_int(char *s);

#endif