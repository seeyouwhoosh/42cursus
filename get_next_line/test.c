/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 23:56:13 by marvin            #+#    #+#             */
/*   Updated: 2025/06/20 23:56:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line.c"

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
size_t totalnlines = 0;

int	main(void)
{
	
		/* ----------------- TESTS DE FUNCIÖN PRINCIPAL -----------------*/
	printf("\nTEST get_next_line: \n");
	FILE *fp = fopen("text.txt", "r");
	char *gline;
	size_t m = 0;
	size_t totalnlinescmp = 0;
	ssize_t nline;
	size_t i = 0;

	int fd = open("text.txt", O_RDONLY);
	char *gnlline;

	while ((nline = getline(&gline, &m, fp)) > -1)
	{
		i++;
		gnlline = get_next_line(fd);
		totalnlinescmp += nline;
		if (strcmp(gnlline, gline))
		{
			printf("Diff in \"%s\" != \"%s\"\n", gnlline, gline);
			m = -1;
			break;
		}
		else
			printf("%ld:\nGNL \"%s\"\nGL \"%s\"\n", i, gnlline, gline);
	}


	free(gline);
	fclose(fp);
	free(gnlline);
	close(fd);

	//system("valgrind --tool=memcheck  --leak-check=full -v ./a.out");
	return (0);
}