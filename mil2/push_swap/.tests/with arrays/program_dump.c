/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_dump.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:26:27 by xwu               #+#    #+#             */
/*   Updated: 2025/07/27 12:16:43 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"
#include "ft_math.h"

void	error_message(void)
{
	write(2, "Error\n", 6);
}

void	pilesfree(int **lst)
{
	if (lst[0])
		free(lst[0]);
	if (lst[1])
		free(lst[1]);
}

int	intreps(int *lst, size_t size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size - 2)
		{
			if (lst[i] == lst[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	intsprint(int *lst, size_t size)
{
	int	i;

	i = -1;
	while (++i < (size - 1))
		ft_printf("%d\n", lst[size]);
}

int	main(int ac, char **av)
{
	int		*lst[2];
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (ac < 2)
		return (0);
	lst[0] = malloc(sizeof(int) * (ac - 1));
	lst[1] = malloc(sizeof(int) * (ac - 1));
	if (!lst[0] || !lst[1])
		return (pilesfree(lst), 1);
	while (++i < ac)
	{
		if (!is_int(av[i]))
			return (pilesfree(lst), error_message(), 1);
		lst[0][j] = ft_atoi(av[i]);
		j++;
	}
	if (intreps(lst[0], ac - 1))
		return (pilesfree(lst), error_message(), 1);

	intsprint(lst[0], ac - 1);
	pilesfree(lst);
	return (0);
}
