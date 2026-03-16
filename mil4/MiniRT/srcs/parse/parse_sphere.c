/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:06:15 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/02/21 18:13:16 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	parse_sphere2(t_miniRT *rt, t_sphere sphere,
		char **nums, char **split)
{
	free_split(nums);
	free_split(split);
	if (!is_color(sphere.r, sphere.g, sphere.b))
		return (WRONG_SPECIFIER);
	sphere.d /= 2.0;
	return (add_sphere(rt->spheres, sphere));
}

int	parse_sphere(t_miniRT *rt, char **split)
{
	char		**nums;
	t_sphere	sphere;

	ft_bzero(&sphere, sizeof(t_sphere));
	if (validate_nums(split[1]))
		return (free_split(split), UNKNOWN_SPECIFIER);
	nums = ft_split(split[1], ',');
	if (!nums[0] || !nums[1] || !nums[2] || nums[3]
		|| ft_atod(nums[0], &(sphere.pos.x))
		|| ft_atod(nums[1], &(sphere.pos.y))
		|| ft_atod(nums[2], &(sphere.pos.z)))
		return (free_split(split), free_split(nums), UNKNOWN_SPECIFIER);
	free_split(nums);
	if (!split[2])
		return (free_split(split), UNKNOWN_SPECIFIER);
	if (ft_atod(split[2], &(sphere.d)))
		return (free_split(split), UNKNOWN_SPECIFIER);
	if (validate_nums(split[3]) || sphere.d <= 0)
		return (free_split(split), UNKNOWN_SPECIFIER);
	nums = ft_split(split[3], ',');
	if (!nums[0] || !nums[1] || !nums[2] || nums[3] || split[4]
		|| ft_ft_atoi(nums[0], &(sphere.r)) || ft_ft_atoi(nums[1], &(sphere.g))
		|| ft_ft_atoi(nums[2], &(sphere.b)))
		return (free_split(split), free_split(nums), UNKNOWN_SPECIFIER);
	return (parse_sphere2(rt, sphere, nums, split));
}
