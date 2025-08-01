/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:49:34 by xwu               #+#    #+#             */
/*   Updated: 2025/07/31 13:43:17 by xwu              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "ft_printf.h"

/* LIST FUNCTIONS THAT ARE NOT INCLUDED IN THE LIBFT */

int		lstrepsint(t_list *lst);

int		lstsortedsint(t_list *lst);

void	lstprint(t_list *lst, char format);

int		ft_minint(t_list *lst);

int		ft_maxint(t_list *lst);


/* OPERATIONS */

void	ft_sa(t_list *lst);

void	ft_pa(t_list **a, t_list **b);

void	ft_ra(t_list **lst);

void	ft_rra(t_list **lst);

void	ft_sb(t_list *lst);

void	ft_pb(t_list **a, t_list **b);

void	ft_rb(t_list **lst);

void	ft_rrb(t_list **lst);

void	ft_ss(t_list *a, t_list *b);

void	ft_rr(t_list **a, t_list **b);

void	ft_rrr(t_list **a, t_list **b);

/* MATHEMATICAL FUNCTIONS */

int		abs(int x);

int		power(int base, int exp);

int		is_int(char *s);

#endif