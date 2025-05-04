/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:57:58 by xwu               #+#    #+#             */
/*   Updated: 2025/05/04 17:27:25 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i])
		i += ft_putchar(s[i]);
	return (i);
}

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		i++;
		i += ft_putnbr(-n);
	}
	else if (n > 10)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
		i++;
	}
	return (i);
}

int	ft_putubnr(unsigned int n)
{
	int	i;

	i = 1;
	if (n >= 10)
		i += ft_putubnr(n / 10);
	ft_putchar((n % 10) + '0');
	return (i);
}

int	ft_puthex(unsigned long n, int upper, int prefix)
{
	char	*hex;
	int		i;

	i = 0;
	if (upper)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (prefix)
	{
		i += ft_putstr("0x");
		prefix = 0;
	}
	if (n >= 16)
		i += ft_puthex(n / 16, upper, prefix);
	ft_putchar(hex[n % 16]);
	i++;
	return (i);
}

int	ft_redirect(char id, va_list args)
{
	if (id == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (id == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (id == 'p')
		return (ft_puthex((uintptr_t)va_arg(args, void *), 0, 1));
	else if (id == 'd' || id == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (id == 'u')
		return (ft_putubnr(va_arg(args, unsigned int)));
	else if (id == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0, 0));
	else if (id == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1, 0));
	else if (id == '%')
		return (ft_putchar('%'));
	else
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
		if (s[i] != '%')
		{
			ft_putchar(s[i]);
			count++;
		}
		else if (s[i + 1])
		{
			count += ft_redirect(s[i + 1], args);
			i++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
