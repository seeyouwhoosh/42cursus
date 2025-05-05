/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 02:06:24 by xwu               #+#    #+#             */
/*   Updated: 2025/05/05 02:28:15 by xwu              ###   ########.fr       */
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
	void *ptr2 = NULL;
 	printf_value = printf("3. Pointer: %p\n", ptr);
	ft_printf_value = ft_printf("   Pointer: %p\n", ptr);
	printf("   Exp: %d	Rea: %d\n\n", printf_value, ft_printf_value);

	printf_value = ft_printf("3.1. Void pointer: %p\n", ptr2);
	ft_printf_value = ft_printf("     Void pointer: %p\n", ptr2);
	printf("     Exp: %d	Rea: %d\n\n", printf_value, ft_printf_value);

	int n = -2147483648;
	printf_value = printf("4. Decimal: %d\n", n);
	ft_printf_value = ft_printf("   Decimal: %d\n", n);
	printf("   Exp: %d	Rea: %d\n\n", printf_value, ft_printf_value);

	printf_value = printf("5. Integer = Decimal: %i\n", n);
	ft_printf_value = ft_printf("   Integer = Decimal: %i\n", n);
	printf("   Exp: %d	Rea: %d\n\n", printf_value, ft_printf_value);

	printf_value = printf("6. Unsigned integer: %u\n", n);
	ft_printf_value = ft_printf("   Unsigned integer: %u\n", n);
	printf("   Exp: %d	Rea: %d\n\n", printf_value, ft_printf_value);

	int hex = 16;
	printf_value = printf("7. Lower hexadecimal: %x\n", hex);
	ft_printf_value = ft_printf("   Lower hexadecimal: %x\n", hex);
	printf("   Exp: %d	Rea: %d\n\n", printf_value, ft_printf_value);

	printf_value = printf("8. Upper hexadecimal: %X\n", hex); 
	ft_printf_value = ft_printf("   Lower hexadecimal: %X\n", hex);
	printf("   Exp: %d	Rea: %d\n\n", printf_value, ft_printf_value);

	
	printf_value = printf("9. Percentage: %%\n");
	ft_printf_value = ft_printf("   Percentage: %%\n");
	printf("   Exp: %d	Rea: %d\n\n", printf_value, ft_printf_value);

	printf("******* END OF THE PRINTF TRIALS *******\n\n");
	printf("Independent testing area \n");

	printf("Characters: %c%c%c%c%c\n", 'a', 'b', 'c', 'd', 'e');
	ft_printf("Characters: %c%c%c%c%c\n", 'a', 'b', 'c', 'd', 'e');
	
	return (0);
}