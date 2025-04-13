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


#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return ;
}


void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
	return ;
}


void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
	return ;
}


void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
        return ;
	}
	if (nb < 0)
    {
        ft_putchar_fd('-', fd);
        ft_putnbr_fd(-nb, fd);
    }
    if (nb >= 10)
    {
        ft_putnbr_fd(nb / 10, fd);
        ft_putnbr_fd(nb % 10, fd);
    }
    else
    {
        ft_putchar_fd(nb + '0', fd);
    }
	return ;
}


/* // Testing ground
#include <stdio.h>
int	main(void)
{
	int character = 's';
	char *string = "Hello, World";

    ft_putchar_fd(character, 1);
	ft_putstr_fd(string, 1);
	ft_putendl_fd(string, 1);
	ft_putnbr_fd(343, 1);
	return (0);
}
// End of testing ground */

