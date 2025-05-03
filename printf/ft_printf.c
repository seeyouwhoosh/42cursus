/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:57:58 by xwu               #+#    #+#             */
/*   Updated: 2025/05/03 14:45:36 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	ft_isspace(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr("(null)");
		return (0);
	}
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
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
		ft_putnbr(-n);
	}
	else if (n > 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
		i++;
	}
	return (i);
}

void	ft_putubnr(unsigned int n)
{
	if (n >= 10)
		ft_putubnr(n / 10);
	ft_putchar((n % 10) + '0');
}
int	ft_strlen(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i++]);
	return (i);
}

int	ft_redirect(char id, va_list args)
{
	char *s;

	if (id == 'c')
		return (ft_putchar(va_arg(args, int)), 1);
	else if (id == 's')
	{
		s = va_arg(args, char *);
		return(ft_putstr(s));
	}
	else if (id == 'p')
		;
	else if (id == 'd' || id == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (id == 'u')
		ft_putubnr(va_arg(args, unsigned int));
	else if (id == 'x')
		;
	else if (id == 'X')
		;
	else if (id == '%')
		return(ft_putchar('%'), 1);
	else
		return (0);
	return (1);
}

int	ft_printf(char const *s, ...)
{
	va_list	args;
	int		i;
	int count;

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
		else
		{
			i++;
			count += ft_redirect(s[i], args);
		}
		i++;
	}
	va_end(args);
	return (count);
}
