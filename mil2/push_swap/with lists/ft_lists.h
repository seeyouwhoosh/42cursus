/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:57:07 by xwu               #+#    #+#             */
/*   Updated: 2025/07/27 12:07:23 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LISTS_H
# define FT_LISTS_H
# include "libft.h"
# include "ft_printf.h"

int		lstrepsint(t_list *lst);

int		lstsortedsint(t_list *lst);

void	lstprint(t_list *lst, char format);

void	lstswap(t_list *lst);

void	lstpush(t_list **a, t_list **b);

void	lstrotate(t_list **lst);

void	lstrrotate(t_list **lst);

#endif