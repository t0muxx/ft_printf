/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 09:26:20 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/08 14:27:01 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		main(void)
{
	printf("FLAG %%\n");
	printf("%% = |%%|\n");
	printf("\nFLAG %%# avec %%o\n");
	printf("%%o = |%o|\n", 8);
	printf("%%#o = |%#o|\n", 8);
	printf("%%O = |%O|\n", 8);
	printf("%%#O = |%#O|\n", 8);
	printf("%%o = |%o|\n", 14);
	printf("%%#o = |%#o|\n", 14);
	printf("%%O = |%O|\n", 14);
	printf("%%#O = |%#O|\n", 14);
	printf("%%o = |%o|\n", -14);
	printf("%%#o = |%#o|\n", -14);
	printf("%%O = |%O|\n", -14);
	printf("%%#O = |%#O|\n", -14);


	printf("\nFLAG %%# avec %%x\n");
	printf("%%x = |%x|\n", 21);
	printf("%%#x = |%#x|\n", 21);
	printf("%%X = |%X|\n", 21);
	printf("%%#X = |%#X|\n", 21);
	printf("%%x = |%x|\n", 14);
	printf("%%#x = |%#x|\n", 14);
	printf("%%X = |%X|\n", 14);
	printf("%%#X = |%#X|\n", 14);
	printf("%%x = |%x|\n", -14);
	printf("%%#x = |%#X|\n", -14);
	printf("%%X = |%x|\n", -14);
	printf("%%#X = |%#x|\n", -14);

	printf("\nFLAG %%0X avec %%d\n");
	printf("%%d = |%d|\n", 1894);
	printf("%%08d = |%08d|\n", 1894);
	printf("%%d = |%d|\n", -1894);
	printf("%%08d = |%08d|\n", -1894);

	printf("\nFLAG %%0X avec %%i\n");
	printf("%%i = |%i|\n", 14);
	printf("%%08i = |%08i|\n", 14);
	printf("%%i = |%i|\n", -14);
	printf("%%08i = |%08i|\n", -14);

	printf("\nFLAG %%0X avec %%o\n");
	printf("%%o = |%o|\n", 14);
	printf("%%08o = |%08o|\n", 14);
	printf("%%o = |%o|\n", -14);
	printf("%%08o = |%08o|\n", -14);
	printf("%%#o = |%#o|\n", 14);
	printf("%%#08o = |%#08o|\n", 14);

	printf("\nFLAG %%0X avec %%u\n");
	printf("%%u = |%u|\n", 14);
	printf("%%07u = |%07u|\n", 14);
	printf("%%u = |%u|\n", -14);
	printf("%%07u = |%07u|\n", -14);
	printf("%%u = |%u|\n", 914);
	printf("%%07u = |%07u|\n", 914);

	printf("\nFLAG %%0X avec %%x\n");
	printf("%%x = |%x|\n", 43);
	printf("%%07x = |%07x|\n", 43);
	printf("%%x = |%x|\n", 914);
	printf("%%07x = |%07x|\n", 914);
	printf("%%#x = |%#x|\n", 914);
	printf("%%#07x = |%#07x|\n", 914);

	printf("\nFLAG %%0X avec %%d\n");
	printf("%%-d = |%-d|\n", 1894);
	printf("%%-08d = |%-08d|\n", 1894);
	printf("%%-d = |-%d|\n", -1894);
	printf("%%-08d = |%-08d|\n", -1894);
	return (0);
}
