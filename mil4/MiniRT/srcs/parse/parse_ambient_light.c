/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 20:14:57 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/03/12 21:49:28 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	parse_ambient_lighting2(t_miniRT *rt, char **split, char **nums)
{
	free_split(nums);
	free_split(split);
	rt->ambient_light->isdef = 1;
	if (!is_color(rt->ambient_light->r, rt->ambient_light->g,
			rt->ambient_light->b))
		return (WRONG_SPECIFIER);
	return (SUCCESS);
}

int	parse_ambient_lighting(t_miniRT *rt, char **split)
{
	char	**nums;

	if (rt->ambient_light->isdef)
		return (free_split(split), MULTIPLE_MANDATORY);
	if (!split[1] || ft_atod(split[1], &(rt->ambient_light->bright)))
		return (free_split(split), UNKNOWN_SPECIFIER);
	if (rt->ambient_light->bright < 0 || rt->ambient_light->bright > 1)
		return (free_split(split), WRONG_SPECIFIER);
	if (validate_nums(split[2]))
		return (free_split(split), UNKNOWN_SPECIFIER);
	nums = ft_split(split[2], ',');
	if (!nums)
		return (free_split(split), MALLOC);
	if (!nums[0] || ft_ft_atoi(nums[0], &(rt->ambient_light->r)))
		return (free_split(nums), free_split(split), UNKNOWN_SPECIFIER);
	if (!nums[1] || ft_ft_atoi(nums[1], &(rt->ambient_light->g)))
		return (free_split(nums), free_split(split), UNKNOWN_SPECIFIER);
	if (!nums[2] || ft_ft_atoi(nums[2], &(rt->ambient_light->b)))
		return (free_split(nums), free_split(split), UNKNOWN_SPECIFIER);
	if (nums[3] || split[3])
		return (free_split(nums), free_split(split), UNKNOWN_SPECIFIER);
	return (parse_ambient_lighting2(rt, split, nums));
}
