/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:22:53 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/03/14 19:12:12 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

char	**ft_reall(char **nums, char *line)
{
	free_split(nums);
	return (ft_split(line, ','));
}

static void	generate_base(t_camera *camera)
{
	camera->right = get_right(camera->dir);
	camera->up = vec_prod(camera->dir, camera->right);
	normalise(&(camera->up));
}

static int	parse_camera2(t_miniRT *rt, char **split, char **nums)
{
	if (!nums[0] || ft_atod(nums[0], &(rt->camera->dir.x)))
		return (free_split(nums), free_split(split), UNKNOWN_SPECIFIER);
	if (!nums[1] || ft_atod(nums[1], &(rt->camera->dir.y)))
		return (free_split(nums), free_split(split), UNKNOWN_SPECIFIER);
	if (!nums[2] || ft_atod(nums[2], &(rt->camera->dir.z)))
		return (free_split(nums), free_split(split), UNKNOWN_SPECIFIER);
	if (nums[3])
		return (free_split(nums), free_split(split), UNKNOWN_SPECIFIER);
	free_split(nums);
	if (validate_dir(&(rt->camera->dir.x), &(rt->camera->dir.y),
			&(rt->camera->dir.z)))
		return (free_split(split), NO_DIR);
	if (!split[3] || ft_ft_atoi(split[3], &(rt->camera->fov))
		|| rt->camera->fov <= 0 || rt->camera->fov > 180)
		return (free_split(split), UNKNOWN_SPECIFIER);
	rt->camera->f = WIDTH / (2 * tan((double)(rt->camera->fov
					* PI / 180.0) / 2.0));
	if (rt->camera->fov > 180 || rt->camera->fov <= 0)
		return (free_split(split), WRONG_SPECIFIER);
	if (split[4])
		return (UNKNOWN_SPECIFIER);
	free_split(split);
	rt->camera->isdef = 1;
	generate_base(rt->camera);
	return (SUCCESS);
}

int	parse_camera(t_miniRT *rt, char **split)
{
	char	**nums;

	if (rt->camera->isdef)
		return (free_split(split), MULTIPLE_MANDATORY);
	if (validate_nums(split[1]))
		return (free_split(split), UNKNOWN_SPECIFIER);
	nums = ft_split(split[1], ',');
	if (!nums)
		return (free_split(split), free_split(nums), MALLOC);
	if (!nums[0] || ft_atod(nums[0], &(rt->camera->pos.x)))
		return (free_split(nums), free_split(split), UNKNOWN_SPECIFIER);
	if (!nums[1] || ft_atod(nums[1], &(rt->camera->pos.y)))
		return (free_split(nums), free_split(split), UNKNOWN_SPECIFIER);
	if (!nums[2] || ft_atod(nums[2], &(rt->camera->pos.z)) || nums[3])
		return (free_split(nums), free_split(split), UNKNOWN_SPECIFIER);
	free_split(nums);
	if (validate_nums(split[2]))
		return (free_split(split), UNKNOWN_SPECIFIER);
	nums = ft_split(split[2], ',');
	if (!nums)
		return (free_split(split), MALLOC);
	return (parse_camera2(rt, split, nums));
}
