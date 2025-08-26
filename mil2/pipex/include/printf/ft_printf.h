/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:46:16 by xwu               #+#    #+#             */
/*   Updated: 2025/07/22 18:35:22 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

int		ft_redirect(char id, va_list args);

int		ft_printf(const char *s, ...);

int		ft_putchar(char c);

int		ft_putstr(char *s);

int		ft_putnbr(int n);

int		ft_putubnr(unsigned int n);

int		ft_puthex(unsigned long n, int upper);

#endif