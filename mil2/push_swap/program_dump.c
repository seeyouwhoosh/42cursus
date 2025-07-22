/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_dump.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:26:27 by xwu               #+#    #+#             */
/*   Updated: 2025/07/22 20:14:58 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	error_message(void)
{
	write(2, "Error\n", 6);
}

int	ft_atoi(char *str)
{
	short	sign;
	int		n;

	sign = 1;
	n = 0;
	if (!str || !(*str))
		return (-1);
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str)
	{
		if (*str == 32 || (*str >= 9 && *str <= 13))
			break ;
		if (*str < 47 || *str > 58)
			return (-1);
		n = n * 10 + (*str - '0');
		str++;
	}
	return (n * sign);
}

int	is_limits(char *s)
{
	if (ft_strlen(s > 9))
		if (*s++ == '2')
			if (ft_atoi(s) > 147483647)
			
}

int	main(int ac, char **av)
{
	int		n;
	size_t	i;

	i = 1;
	if (ac < 2)
		return (error_message(), 1);
	while (i < ac)
	{
		printf("%s == ", av[i]);
		n = ft_atoi(av[i]);
		printf("%d\t", n);
		if (n == -1)
			return (error_message(), 1); /* +liberar lista */
		/* añadir valor a lista */
		/* */
		i++;
	}
	return (0);
}
