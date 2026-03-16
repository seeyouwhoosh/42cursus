/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:55:22 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/03/14 14:12:31 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		if (split[i])
			free(split[i]);
		i++;
	}
	free(split);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return ((int)s1[i] - (int)s2[i]);
}

int	parse(t_miniRT *rt, char *line)
{
	char	**split;

	while (*line == ' ')
		line++;
	if (!line[0])
		return (SUCCESS);
	split = ft_split(line, ' ');
	if (!split)
		return (MALLOC);
	if (!ft_strcmp(split[0], "A"))
		return (parse_ambient_lighting(rt, split));
	else if (!ft_strcmp(split[0], "L"))
		return (parse_light(rt, split));
	if (!ft_strcmp(split[0], "C"))
		return (parse_camera(rt, split));
	if (!ft_strcmp(split[0], "sp"))
		return (parse_sphere(rt, split));
	else if (!ft_strcmp(split[0], "cy"))
		return (parse_cylinder(rt, split));
	else if (!ft_strcmp(split[0], "pl"))
		return (parse_plane(rt, split));
	return (free_split(split), UNKNOWN_SPECIFIER);
}
