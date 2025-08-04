/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:57:58 by xwu               #+#    #+#             */
/*   Updated: 2025/07/22 18:35:12 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdint.h>
#include "ft_printf.h"

int	ft_redirect(char id, va_list args)
{
	char	*ptr;

	if (id == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (id == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (id == 'p')
	{
		ptr = va_arg(args, void *);
		if (!ptr)
			return (ft_putstr("(nil)"));
		ft_putstr("0x");
		return (2 + ft_puthex((uintptr_t)ptr, 0));
	}
	else if (id == 'd' || id == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (id == 'u')
		return (ft_putubnr(va_arg(args, unsigned int)));
	else if (id == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	else if (id == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1));
	else if (id == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(char const *s, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == '\0')
				break ;
			count += ft_redirect(s[i], args);
		}
		else
		{
			ft_putchar(s[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
