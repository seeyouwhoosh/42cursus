/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 18:07:12 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/03/13 00:35:30 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	validate_file(int ac, char **av)
{
	int	i;

	if (ac != 2)
		return (IN_AM);
	if (ft_strlen(av[1]) < 4)
		return (FILE_NAME);
	i = 0;
	while (av[1][i] && av[1][i] != '.')
		i++;
	if (!av[1][i] || !av[1][i + 1] || !av[1][i + 2] || av[1][i + 1] != 'r'
			|| av[1][i + 2] != 't' || av[1][i + 3])
		return (FILE_NAME);
	return (SUCCESS);
}

int	validate_nums(char *nums)
{
	size_t	len;

	if (!nums)
		return (UNKNOWN_SPECIFIER);
	len = ft_strlen(nums);
	if (!nums[0] || nums[0] == ','
		|| ft_strnstr(nums, ",,", len) || nums[len - 1] == ',')
		return (UNKNOWN_SPECIFIER);
	return (SUCCESS);
}

int	validate_dir(double *x, double *y, double *z)
{
	double	ab;

	if (*x == 0.0 && *y == 0.0 && *z == 0.0)
		return (NO_DIR);
	ab = sqrt(mod(*x, *y, *z));
	*x /= ab;
	*y /= ab;
	*z /= ab;
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_miniRT	*rt;
	int			flag;

	flag = validate_file(ac, av);
	rt = ft_calloc(sizeof(t_miniRT), 1);
	if (!rt)
		return (errormsg(MALLOC), 1);
	flag = init(rt, av[1]);
	if (flag)
	{
		errormsg(flag);
		free_all(rt);
		return (1);
	}
	start(rt);
	ft_putendl_fd("Finished!", 1);
	free_all(rt);
}
