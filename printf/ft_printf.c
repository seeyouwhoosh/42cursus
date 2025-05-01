/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:57:58 by xwu               #+#    #+#             */
/*   Updated: 2025/05/01 18:41:05 by xwu              ###   ########.fr       */
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

int	ft_printf(char const *s, ...)
{
	va_list	args;
	int		i;

	va_start(args, s);
	while (s[i])
	{
		if (s[i] != '%')
			ft_putchar(s[i]);
		else
		{
			i++;
			if (s[i] == 'c')
			{
				putchar(va_arg(args, char));
			}
		}
		i++;
	}
	return (0);
}
#include <stdio.h>
int	main(int argc, char **argv)
{
	printf("The printf trials: \n");
	
	char c = 'a';
	printf("char %c", c);
	return (0);
}
