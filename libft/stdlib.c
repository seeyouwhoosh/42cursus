/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unistd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:23:07 by xwu               #+#    #+#             */
/*   Updated: 2025/04/12 13:29:38 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_isdigit(int c);
int	ft_isspace(int c);

int ft_atoi(const char *str)
{
    int index;
    int number;
    int sign;

    index = 0;
    number = 0;
    sign = 1;

    while (ft_isspace(str[index]))
    {
        index++;
    }
    while (str[index] == '-' || str[0] == '+') // el atoi de la librería estandar no acepta múltiples signos
    {
        if (str[index] == '-')
        {
            sign *= -1;
        }
        index++;
    }
    while (ft_isdigit(str[index]))
    {
        number = number * 10 + (str[index] - '0');
        index++;
    }
    return (number * sign);
}

// Testing ground
#include <stdio.h>
int	main(void)
{
	char *s = "    ----23 122";

    printf("Number: %d", ft_atoi(s));
	return (0);
}
// End of testing ground */