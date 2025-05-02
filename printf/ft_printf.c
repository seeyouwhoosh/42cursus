/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:57:58 by xwu               #+#    #+#             */
/*   Updated: 2025/05/03 10:25:44 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

/* Reference thingy
void foo(char *fmt, ...)
{
	va_list ap;
	int d;
	char c;
	char *s;

	va_start(ap, fmt);
	while (*fmt)
		switch (*fmt++) {
		case 's':         
			s = va_arg(ap, char *);
			printf("string %s\n", s);
			break;
		case 'd':      
			d = va_arg(ap, int);
			printf("int %d\n", d);
			break;
		case 'c':         
			c = (char) va_arg(ap, int);
			printf("char %c\n", c);
			break;
		}
	va_end(ap);
}
*/

int	ft_isspace(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
}

int	ft_redirect(char id, va_list args)
{
	if (id == 'c')
		ft_putchar(va_arg(args, int));
	else if (id == 's')
		ft_putstr(va_arg(args, char *));
	else if (id == 'p')
		ft_putstr(va_arg(args, char *));
	else if (id == '%')
		ft_putchar(id);
	else if (id == 'd')
		;
	else if (id == 'i')
		;
	else if (id == 'u')
		;
	else if (id == 'x')
		;
	else if (id == 'X')
		;
	else
		return (0);
	return (1);
}

int	ft_printf(char const *s, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] != '%')
			ft_putchar(s[i]);
		else
		{
			while (ft_isspace(s[i + 1]))
				i++;
			i += ft_redirect(s[i + 1], args);
		}
		i++;
	}
	return (0);
}
