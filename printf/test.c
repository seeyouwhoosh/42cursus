/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 02:06:24 by xwu               #+#    #+#             */
/*   Updated: 2025/05/03 17:21:26 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	int	printf_value = 0;
	int	ft_printf_value = 0;
	printf("\n********** THE PRINTF TRIALS **********\n");
	
	printf_value = printf("0. Preliminary tests: \n \
		Nórmâl text! :D ñu \n \
		\\ Escape \t text \n");
	ft_printf_value = ft_printf("   Preliminary tests: \n \
		Nórmâl text! :D ñu \n \
		\\ Escape \t text \n");
	printf("   Exp: %d	Rea: %d\n\n", printf_value, ft_printf_value);
		
	char c = 'a';
	printf_value = printf("1. Character: %c\n", c);
	ft_printf_value = ft_printf("   Character: %c\n", c);
	printf("   Exp: %d	Rea: %d\n\n", printf_value, ft_printf_value);

	
	char *str = "Hello World";
	printf_value = printf("2. String: %s\n", str);
	ft_printf_value = ft_printf("   String: %s\n", str);
	printf("   Exp: %d	Rea: %d\n\n", printf_value, ft_printf_value);


	void *ptr = str;
	void *ptr2 = 0;
 	printf_value = printf("3. Pointer: %p\n", ptr);
	ft_printf_value = ft_printf("3.1. Void pointer: %p\n", ptr2);


	int n = -2384;
	printf_value = printf("4. Decimal: %d\n", n);
	ft_printf_value = ft_printf("   Decimal: %d\n", n);
	printf("   Exp: %d	Rea: %d\n\n", printf_value, ft_printf_value);


	printf_value = printf("5. Integer = Decimal: %i\n", n);
	ft_printf_value = ft_printf("   Integer = Decimal: %i\n", n);
	printf("   Exp: %d	Rea: %d\n\n", printf_value, ft_printf_value);


	printf_value = printf("6. Unsigned integer: %u\n", n);
	ft_printf_value = ft_printf("   Unsigned integer: %u\n", n);
	printf("   Exp: %d	Rea: %d\n\n", printf_value, ft_printf_value);

	printf_value = printf("7. Lower hexadecimal: %x\n", c);
	printf_value = printf("8. Upper hexadecimal: %X\n", c); 
	printf_value = printf("9. Percentage: %%%                %\n"); /* WTH, you can put whitespaces, watch out */
	ft_printf_value = ft_printf("   Percentage: %%%                %\n");
	printf("   Exp: %d	Rea: %d\n\n", printf_value, ft_printf_value);

	printf("******* END OF THE PRINTF TRIALS *******\n\n");
	return (0);
}