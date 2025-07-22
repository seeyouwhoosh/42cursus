/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:24:20 by xwu               #+#    #+#             */
/*   Updated: 2025/07/22 19:24:40 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	error_message(void)
{
	return (write(2, "Error\n", 6));
}

int	main(int ac, char **av)
{
	int	n;

	if (ac < 1)
		return (error_message(), 1);
	while (**av)
	{
		n = ft_atoi(**av);
		if (n < 0)
			return (error_message(), 1); // +liberal lista
		// añadir valor a lista
		(*av)++;
	}
	return (0);
}