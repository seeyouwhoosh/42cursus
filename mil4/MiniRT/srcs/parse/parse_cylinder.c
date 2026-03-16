/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 19:58:12 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/02/21 18:24:01 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	parse_cylinder3(char **split, t_cylinder *cylinder)
{
	ft_bzero(cylinder, sizeof(t_cylinder));
	if (validate_nums(split[1]))
		return (free_split(split), UNKNOWN_SPECIFIER);
	return (SUCCESS);
}

static int	parse_cylinder2(t_miniRT *rt, char **nums, char **split,
		t_cylinder cylinder)
{
	if (validate_dir(&(cylinder.dir.x), &(cylinder.dir.y), &(cylinder.dir.z)))
		return (free_split(split), NO_DIR);
	if (!split[4] || ft_atod(split[4], &(cylinder.h)))
		return (free_split(split), UNKNOWN_SPECIFIER);
	if (cylinder.h <= 0)
		return (free_split(split), WRONG_SPECIFIER);
	if (validate_nums(split[5]))
		return (free_split(split), UNKNOWN_SPECIFIER);
	nums = ft_split(split[5], ',');
	if (!nums[0] || !nums[1] || !nums[2] || nums[3]
		|| ft_ft_atoi(nums[0], &(cylinder.r))
		|| ft_ft_atoi(nums[1], &(cylinder.g))
		|| ft_ft_atoi(nums[2], &(cylinder.b)) || split[6])
		return (free_split(split), free_split(nums), UNKNOWN_SPECIFIER);
	free_split(nums);
	free_split(split);
	if (!is_color(cylinder.r, cylinder.g, cylinder.b))
		return (WRONG_SPECIFIER);
	cylinder.d /= 2.0;
	if (add_cylinder(rt->cylinders, cylinder))
		return (MALLOC);
	return (SUCCESS);
}

int	parse_cylinder(t_miniRT *rt, char **split)
{
	char		**nums;
	t_cylinder	cylinder;

	if (parse_cylinder3(split, &cylinder))
		return (free_split(split), UNKNOWN_SPECIFIER);
	nums = ft_split(split[1], ',');
	if (!nums[0] || !nums[1] || !nums[2] || nums[3]
		|| ft_atod(nums[0], &(cylinder.pos.x))
		|| ft_atod(nums[1], (&cylinder.pos.y))
		|| ft_atod(nums[2], &(cylinder.pos.z)))
		return (free_split(split), free_split(nums), UNKNOWN_SPECIFIER);
	free_split(nums);
	if (validate_nums(split[2]))
		return (free_split(split), UNKNOWN_SPECIFIER);
	nums = ft_split(split[2], ',');
	if (!nums[0] || !nums[1] || !nums[2] || nums[3]
		|| ft_atod(nums[0], &(cylinder.dir.x))
		|| ft_atod(nums[1], &(cylinder.dir.y))
		|| ft_atod(nums[2], &(cylinder.dir.z)))
		return (free_split(split), free_split(nums), UNKNOWN_SPECIFIER);
	if (!split[3] || ft_atod(split[3], &(cylinder.d)))
		return (free_split(nums), free_split(split), UNKNOWN_SPECIFIER);
	if (cylinder.d <= 0)
		return (free_split(nums), free_split(split), UNKNOWN_SPECIFIER);
	return (free_split(nums), parse_cylinder2(rt, nums, split, cylinder));
}
