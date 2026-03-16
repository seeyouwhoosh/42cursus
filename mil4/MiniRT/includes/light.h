/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 21:50:17 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/03/01 14:30:13 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

typedef struct s_light
{
	double	bright;
	int		r;
	int		g;
	int		b;
	t_vec	pos;
	char	isdef;
}	t_light;

#endif
