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

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
size_t totalnlines = 0;
#include "get_next_line.c"

int	main(void)
{
	char list[][100] = {"", "Hello World\n", "Esto es \n una línea nueva", " ", "\n"};

	/* ----------------- TESTS DE FUNCIONES AUXILIARES -----------------*/
	printf("\nTEST ft_strlen: ");
	size_t n;
	size_t ncomp;
	for (size_t i = 0; i < 5; i++)
	{
		if ((n = ft_strlen(list[i])) != (ncomp = strlen(list[i])))
		{
			printf("Break in %ld\n", i);
			n = -1;
			break;
		}
	}
	if (n != -1)
		printf("Pass");

	printf("\nTEST ft_strchr: ");
	char *s;
	char *scomp;
	for (size_t i = 0; i < 5; i++)
	{
		if ((s = ft_strchr(list[i], '\n')) != (scomp = ft_strchr(list[i], '\n')))
		{
			printf("Break in %ld\n", i);
			s = NULL;
			break;
		}
	}
	if (s)
		printf("Pass");

	printf("\nTEST ft_strpdump (MANUAL)\n");
	char **lines = malloc(sizeof(char *) * 5);
	char correct_lines[][128] = {"", "Hello World\n", "Esto es \n", " ", "\n"};
	for (size_t i = 0; i < 5; i++)
	{
		size_t ndump = ft_strpdump(&(lines[i]), list[i], ft_strchr(list[i], '\n'));
		int ncmp = strcmp(lines[i], correct_lines[i]);
		printf("---\nString to dump: \"%s\"\nString dumped:\"%s\"\nCharacters dumped: %ld\nComparison return: %d\n---", list[i], lines[i], ndump, ncmp);
		if (ncmp)
		{
			printf("Break in %ld\n", i);
			s = NULL;
			break;
		}
	}
	for (size_t i = 0; i < 5; i++)
		free(lines[i]);
	free(lines);
	if (s)
		printf("\nTEST result: Pass\n");



	/* ----------------- TESTS DE FUNCIÖN PRINCIPAL -----------------*/

	printf("\nTEST get_next_line: ");
	FILE *fp = fopen("text.txt", "r");
	char *gline;
	size_t m = 0;
	size_t totalnlinescmp = 0;
	ssize_t nline;

	int fd = open("text.txt", O_RDONLY);
	char *gnlline;

	while ((nline = getline(&gline, &m, fp)) > -1)
	{
		gnlline = get_next_line(fd);
		totalnlinescmp += nline;
		if (strcmp(gnlline, gline))
		{
			printf("Diff in \"%s\" != \"%s\"\n", gnlline, gline);
			m = -1;
			break;
		}
	}

	printf("%s", (totalnlines == totalnlinescmp)? "Pass\n": "Break");
	if (totalnlines != totalnlinescmp)
		printf(" in %ld != %ld\n", totalnlines, totalnlinescmp);
	
	free(gline);
	fclose(fp);
	free(gnlline);
	close(fd);

	system("valgrind --tool=memcheck  --leak-check=full -v ./a.out");
	return (0);
}