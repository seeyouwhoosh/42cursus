/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_dump.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:26:27 by xwu               #+#    #+#             */
/*   Updated: 2025/07/27 11:51:56 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

void	error_message(void)
{
	write(2, "Error\n", 6);
}

int	abs(int x)
{
	return (x * ((x > 0) - (x < 0)));
}

int	power(int base, int exp)
{
	int	n;

	n = 1;
	while (exp)
	{
		n *= base;
		exp --;
	}
	return (n);
}

int	is_int(char *s)
{
	int	conv;
	int	i;
	int	sign;

	sign = 0;
	i = ft_strlen(s);
	conv = ft_atoi(s);
	if (s[0] == '-')
	{
		if (conv > 0)
			return (0);
		sign = 1;
	}
	conv = abs(conv);
	while (i > sign)
	{
		if ((s[i - 1] - '0') != (conv % 10))
			return (0);
		conv /= 10;
		i--;
	}
	return (1);
}



int	main(int ac, char **av)
{
	int		*n;
	int		i;
	t_list	*lst;
	t_list	*new;

	lst = NULL;

	i = 1;
	if (ac < 2)
		return (error_message(), 1);
	while (i < ac)
	{
		n = malloc(sizeof(int));
		if (!is_int(av[i]) || !n)
			return (ft_lstclear(&lst, del), error_message(), 1);
		*n = ft_atoi(av[i]);
		new = ft_lstnew(n);
		ft_lstadd_back(&lst, new);
		i++;
	}
	ft_lstprint(lst, 'd');
	return (free(n), free(new), 0);
}
