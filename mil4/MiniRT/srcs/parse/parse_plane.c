/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 19:19:58 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/02/18 19:19:12 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	parse_plane2(t_miniRT *rt, char **nums, char **split, t_plane plane)
{
	if (!nums[0] || !nums[1] || !nums[2] || nums[3]
		|| ft_ft_atoi(nums[0], &(plane.r)) || ft_ft_atoi(nums[1], &(plane.g))
		|| ft_ft_atoi(nums[2], &(plane.b)))
		return (free_split(split), free_split(nums), UNKNOWN_SPECIFIER);
	free_split(nums);
	if (validate_dir(&(plane.dir.x), &(plane.dir.y), &(plane.dir.z)))
		return (free_split(split), NO_DIR);
	if (!is_color(plane.r, plane.b, plane.g))
		return (free_split(split), WRONG_SPECIFIER);
	if (split[4])
		return (free_split(split), UNKNOWN_SPECIFIER);
	free_split(split);
	if (add_plane(rt->planes, plane))
		return (MALLOC);
	return (SUCCESS);
}

int	parse_plane(t_miniRT *rt, char **split)
{
	char	**nums;
	t_plane	plane;

	ft_bzero(&plane, sizeof(plane));
	if (validate_nums(split[1]))
		return (free_split(split), UNKNOWN_SPECIFIER);
	nums = ft_split(split[1], ',');
	if (!nums[0] || !nums[1] || !nums[2] || nums[3]
		|| ft_atod(nums[0], &(plane.pos.x)) || ft_atod(nums[1], (&plane.pos.y))
		|| ft_atod(nums[2], &(plane.pos.z)))
		return (free_split(split), free_split(nums), UNKNOWN_SPECIFIER);
	free_split(nums);
	if (validate_nums(split[2]))
		return (free_split(split), UNKNOWN_SPECIFIER);
	nums = ft_split(split[2], ',');
	if (!nums[0] || !nums[1] || !nums[2] || nums[3]
		|| ft_atod(nums[0], &(plane.dir.x)) || ft_atod(nums[1], &(plane.dir.y))
		|| ft_atod(nums[2], &(plane.dir.z)))
		return (free_split(split), free_split(nums), UNKNOWN_SPECIFIER);
	free_split(nums);
	if (validate_nums(split[3]))
		return (free_split(split), UNKNOWN_SPECIFIER);
	nums = ft_split(split[3], ',');
	return (parse_plane2(rt, nums, split, plane));
}
