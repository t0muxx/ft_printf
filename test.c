/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 09:26:20 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/09 14:42:54 by tomlulu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <wchar.h>

int		main(void)
{
	/*
	printf("FLAG %%\n");
	printf("%% = |%%|\n");

	// ################ FLAG "#" ##########################
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

// ################ FLAG "0" ##########################
	printf("\nFLAG %%0X avec %%d\n");
	printf("%%d = |%d|\n", 1894);
	printf("%%0d = |%*d|\n", 1894);
	printf("%%d = |%d|\n", -1894);
	printf("%%0d = |%0-9d|\n", -1894);

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

	printf("\nFLAG %%-0X avec %%d\n");
	printf("%%-d = |%-8d|\n", 1894);
	printf("%%-08d = |%-08d|\n", 1894);
	printf("%%-d = |%-8d|\n", -1894);
	printf("%%-08d = |%-08d|\n", -1894);
*/
// ################ FLAG "-" ##########################

	printf("\nFLAG %%-X avec %%d\n");
	printf("%%d = |%d|\n", 1894);
	printf("%%-5d = |%-5d|\n", 1894);
	printf("%%d = |%d|\n", -1894);
	printf("%%-10d = |%-10d|\n", -1894);

	printf("\nFLAG %%-X avec %%i\n");
	printf("%%i = |%i|\n", 1894);
	printf("%%-5i = |%-5i|\n", 1894);
	printf("%%i = |%d|\n", -1894);
	printf("%%-10i = |%-10i|\n", -1894);

	printf("\nFLAG %%-X avec %%o\n");
	printf("%%o = |%o|\n", 14);
	printf("%%-8o = |%-8o|\n", 14);
	printf("%%o = |%o|\n", -14);
	printf("%%-8o = |%-8o|\n", -14);

	printf("\nFLAG %%-X avec %%u\n");
	printf("%%u = |%u|\n", 14);
	printf("%%-7u = |%-7u|\n", 14);
	printf("%%u = |%u|\n", -14);
	printf("%%-7u = |%-7u|\n", -14);
	printf("%%u = |%u|\n", 914);
	printf("%%-7u = |%-7u|\n", 914);

	printf("\nFLAG %%-X avec %%x\n");
	printf("%%x = |%x|\n", 43);
	printf("%%-7x = |%-7x|\n", 43);
	printf("%%x = |%x|\n", 914);
	printf("%%-7x = |%-7x|\n", 914);

	printf("\nFLAG %%-X avec %%s\n");
	printf("%%s = |%s|\n", "yo");
	printf("%%-7s = |%-7s|\n", "yo");
	printf("%%s = |%s|\n", "yoo");
	printf("%%-7s = |%%%%|\n", "yoo");
/*
// ################ FLAG " " & "+" ##########################
	printf("\nFLAG %%_ (space) avec %% d\n");
	printf("%% d = |% d|\n", 1894);
	printf("%% d = |% d|\n", 1894);
	printf("%% d = |% d|\n", -1894);
	printf("%% d = |% d|\n", -1894);

	printf("\nFLAG %%_ (space)avec %% i\n");
	printf("%% i = |% i|\n", 1894);
	printf("%% i = |% i|\n", 1894);
	printf("%% i = |% i|\n", -1894);
	printf("%% i = |% i|\n", -1894);

	printf("\nFLAG %%+ avec %%+d\n");
	printf("%%+d = |%+d|\n", 1894);
	printf("%%+d = |%+d|\n", 1894);
	printf("%%+d = |%+d|\n", -1894);
	printf("%%+d = |%+d|\n", -1894);

	printf("\nFLAG %%+ avec %%+i\n");
	printf("%%+i = |%+i|\n", 1894);
	printf("%%+i = |%+i|\n", 1894);
	printf("%%+i = |%+i|\n", -1894);
	printf("%%+i = |%+i|\n", -1894);

	printf("\nFLAG %%+ avec %%+o\n");
	printf("%%+d = |%+o|\n", 1894);
	printf("%%+d = |%+o|\n", 1894);

	printf("\nFLAG %%+ avec %%+u\n");
	printf("%%+u = |%+u|\n", 1894);
	printf("%%+u = |%+u|\n", 1894);

	printf("\nFLAG %%+ avec %%+x\n");
	printf("%%+x = |%+x|\n", 1894);
	printf("%%+x = |%+x|\n", 1894);

// ################ PRECISION ##########################
	printf("\nTEST PRECISIOn \n");
	printf("%%d = |%d|\n", 10000);
	printf("%%.4d = |%.4d|\n", 10000);
	printf("%%d = |%d|\n", -10000);
	printf("%%.4d = |%.4d|\n", -10000);
	printf("%%d = |%d|\n", 100);
	printf("%%.4d = |%.4d|\n", 100);
	printf("%%d = |%d|\n", -100);
	printf("%%.4d = |%.4d|\n", -100);

	printf("%%i = |%i|\n", 10000);
	printf("%%.4i = |%.4i|\n", 10000);
	printf("%%i = |%i|\n", -10000);
	printf("%%.4i = |%.4i|\n", -10000);
	printf("%%i = |%i|\n", 100);
	printf("%%.4i = |%.4i|\n", 100);
	printf("%%i = |%i|\n", -100);
	printf("%%.4i = |%.4i|\n", -100);

	wchar_t texte[50] = L"Salut Gerard !\0";

	printf("%%s = |%s|\n", "ceci est un test");
	printf("%%.4s = |%.4s|\n", "ceci est un test");
	printf("%%S = |%S|\n", texte);
	printf("%%S = |%.4S|\n", texte);

// ################ FLAG "hh" ##########################
	int a = 165;

	printf("\nTEST FLAG hh \n");
	printf("%%d = |%d|\n", a);
	printf("%%hhd = |%hhd|\n", a);

// ################ FLAG "h" ##########################
	a = 38767;

	printf("\nTEST FLAG h \n");
	printf("%%d = |%d|\n", a);
	printf("%%hd = |%hd|\n", a);

// ################ FLAG "l" ##########################
	printf("\nTEST FLAG l \n");
	printf("%%d = |%d|\n", a);
	printf("%%hd = |%ld|\n", a);

// ################ FLAG "ll" ##########################
	printf("\nTEST FLAG ll \n");
	printf("%%d = |%d|\n", a);
	printf("%%hd = |%lld|\n", a);

// ################ FLAG "ll" ##########################
	printf("\nTEST FLAG ll \n");
	printf("%%d = |%d|\n", 2147483649);
	printf("%%hd = |%jd|\n", 2147483649);

	printf("|%#*d|\n", 5 , 15);
	printf("|%2$*1$d|\n", 5 , 15);
	printf("|%*d||%*d|\n", 5 , 15, 6, 19);
	printf("|%10$*1$d|\n", 5 , 15, 16, 1, 1, 1, 1, 1, 1);
	*/
	return (0);
}
