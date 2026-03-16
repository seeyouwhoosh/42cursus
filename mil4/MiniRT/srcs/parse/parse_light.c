/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 20:15:42 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/03/08 18:57:13 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	parse_light2(t_miniRT *rt, char **split, char **nums)
{
	if (ft_atod(split[2], &(rt->light->bright)))
		return (free_split(nums), free_split(split), UNKNOWN_SPECIFIER);
	if (rt->light->bright < 0 || rt->light->bright > 1)
		return (free_split(split), WRONG_SPECIFIER);
	if (validate_nums(split[3]))
		return (free_split(split), UNKNOWN_SPECIFIER);
	nums = ft_split(split[3], ',');
	if (!nums)
		return (free_split(split), MALLOC);
	if (!nums[0] || ft_ft_atoi(nums[0], &(rt->light->r)))
		return (free_split(nums), free_split(split), UNKNOWN_SPECIFIER);
	if (!nums[1] || ft_ft_atoi(nums[1], &(rt->light->g)))
		return (free_split(nums), free_split(split), UNKNOWN_SPECIFIER);
	if (!nums[2] || ft_ft_atoi(nums[2], &(rt->light->b)))
		return (free_split(nums), free_split(split), UNKNOWN_SPECIFIER);
	if (nums[3] || split[4] || !is_color(rt->light->r,
			rt->light->g, rt->light->b))
		return (free_split(nums), free_split(split), UNKNOWN_SPECIFIER);
	free_split(nums);
	free_split(split);
	rt->light->isdef = 1;
	return (SUCCESS);
}

int	parse_light(t_miniRT *rt, char **split)
{
	char	**nums;

	if (rt->light->isdef)
		return (free_split(split), MULTIPLE_MANDATORY);
	if (validate_nums(split[1]))
		return (free_split(split), UNKNOWN_SPECIFIER);
	nums = ft_split(split[1], ',');
	if (!nums)
		return (free_split(split), MALLOC);
	if (!nums[0] || ft_atod(nums[0], &(rt->light->pos.x)))
		return (free_split(nums), free_split(split), UNKNOWN_SPECIFIER);
	if (!nums[1] || ft_atod(nums[1], &(rt->light->pos.y)))
		return (free_split(nums), free_split(split), UNKNOWN_SPECIFIER);
	if (!nums[2] || ft_atod(nums[2], &(rt->light->pos.z)))
		return (free_split(nums), free_split(split), UNKNOWN_SPECIFIER);
	if (nums[3])
		return (free_split(nums), free_split(split), UNKNOWN_SPECIFIER);
	free_split(nums);
	if (!split[2])
		return (free_split(split), UNKNOWN_SPECIFIER);
	return (parse_light2(rt, split, nums));
}
