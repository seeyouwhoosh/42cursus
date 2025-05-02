/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 02:06:24 by xwu               #+#    #+#             */
/*   Updated: 2025/05/03 09:37:35 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	printf("********** THE PRINTF TRIALS **********\n");
	
	printf("0. Preliminary tests: \n \
		Nórmâl text! :D ñu \n \
		\\ Escape \t text \n");
	ft_printf("   Preliminary tests: \n \
		Nórmâl text! :D ñu \n \
		\\ Escape \t text \n");
		
	char c = 'a';
	printf("1. Character: %c\n", c);
	ft_printf("   Character: %c\n", c);
	
	char *str = "Hello, World";
	printf("2. String: %s\n", str);
	ft_printf("   String: %s\n", str);

	void *ptr = str;
	void *ptr2 = 0;
 	printf("3. Pointer: %p\n", ptr);
	printf("3.1. Void pointer: %p\n", ptr2);

	
/* 	printf("4. Decimal: %d\n", c);
	printf("5. Integer: %i\n", c);
	printf("6. Unsigned integer: %u\n", c);
	printf("7. Lower hexadecimal: %x\n", c);
	printf("8. Upper hexadecimal: %X\n", c);  */
	printf("9. Percentage: %                %\n"); /* WTH, you can put whitespaces, watch out */
	ft_printf("   Percentage: %                %\n");
	
	printf("******* END OF THE PRINTF TRIALS *******\n");
	return (0);
}