/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 01:47:06 by xwu               #+#    #+#             */
/*   Updated: 2025/05/05 02:32:20 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	if (!s)
		return (ft_putstr("(null)"));
	i = 0;
	while (s[i])
		i += ft_putchar(s[i]);
	return (i);
}

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	else if (n < 0)
		i += ft_putchar('-') + ft_putnbr(-n);
	else if (n >= 10)
		i += ft_putnbr(n / 10) + ft_putnbr(n % 10);
	else
		i += ft_putchar(n + '0');
	return (i);
}

int	ft_putubnr(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 10)
		i += ft_putubnr(n / 10);
	ft_putchar((n % 10) + '0');
	i++;
	return (i);
}

int	ft_puthex(unsigned long n, int upper)
{
	char	*hex;
	int		i;

	i = 0;
	if (upper)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (n >= 16)
		i += ft_puthex(n / 16, upper);
	ft_putchar(hex[n % 16]);
	i++;
	return (i);
}