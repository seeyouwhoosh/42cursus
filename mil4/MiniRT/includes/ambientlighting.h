/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambientlighting.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 21:42:04 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/03/14 11:10:38 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMBIENTLIGHTING_H
# define AMBIENTLIGHTING_H

typedef struct s_AmbientLight
{
	double	bright;
	int		r;
	int		g;
	int		b;
	char	isdef;
}	t_AmbientLight;

#endif
