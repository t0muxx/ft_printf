/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:58:00 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/23 09:28:34 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_test.h"
#include <locale.h>

int	main(int argc, char **argv)
{
	int ret;
	int i;
	setlocale(LC_ALL, "en_US.UTF-8");

	ret = 0;
	if (argc == 1)
		return (0);
	if (atoi(argv[1]) == 1)
		test_convert_printf();
	if (atoi(argv[1]) == 2)
		test_convert();
	if (atoi(argv[1]) == 3)
		test_fuzz_opt();
	if (atoi(argv[1]) == 4)
		test_big_width_prec_argnbr();
	if (atoi(argv[1]) == 5)
	{
	/*	ft_printf("|%X|\n", -42);
		printf("|%X|\n", -42);
		ft_printf("|%X|\n", 4294967296);
		printf("|%X|\n", 4294967296);
		ft_printf("|%#08x|\n", 42);
		printf("|%#08x|\n", 42);
		ft_printf("@moulitest: |%5.x| |%5.0x|\n", 0, 0);
		printf("@moulitest: |%5.x| |%5.0x|\n", 0, 0);
		ft_printf("|%-+12.10lx|\n", 42);
		printf("|%-+12.10lx|\n", 42);
		ft_printf("|%.0lld|\n", 0);
		printf("|%.0lld|\n", 0);
		ft_printf("|%.2c|\n", NULL);
		printf("|%.2c|\n", NULL);
		ft_printf("@moulitest: |%c|\n", 0);
		printf("@moulitest: |%c|\n", 0);
		ft_printf("|%2c|\n", 0);
		printf("|%2c|\n", 0);
		ft_printf("null |%c| and text\n", 0);
		printf("null |%c| and text\n", 0);
		ft_printf("|% c|\n", 0);
		printf("|% c|\n", 0);
		ft_printf("@moulitest: |%5.o| |%5.0o|\n", 0, 0);
		printf("@moulitest: |%5.o| |%5.0o|\n", 0, 0);
		ft_printf("@moulitest: |%#.o| |%#.0o|\n", 0, 0);
		printf("@moulitest: |%#.o| |%#.0o|\n", 0, 0);
		ft_printf("@moulitest: |%.d| |%.0d|\n", 42, 43);
		printf("@moulitest: |%.d| |%.0d|\n", 42, 43);
		ft_printf("@moulitest: |%5.d| |%5.0d|\n", 0, 0);
		printf("@moulitest: |%5.d| |%5.0d|\n", 0, 0);
		ft_printf("|%hU|\n", 4294967296);
		printf("|%hU|\n", 4294967296);
		ft_printf("%d\n", 0);
		ft_printf("%hd\n", 0);
		ft_printf("%hhd\n", 0);
		ft_printf("%ld\n", 0);
		ft_printf("%lld\n", 0);
		printf("%d\n", 0);
		printf("%hd\n", 0);
		printf("%hhd\n", 0);
		printf("%ld\n", 0);
		printf("%lld\n", 0);*/
	/*	ret = ft_printf("|%2c|\n", 0);
		printf("%d\n", ret);
		ret = printf("|%2c|\n", 0);
		printf("%d\n", ret);*/
		ft_printf("{%05.Z}\n", 0);
		printf("{%05.Z}\n", 0);
	 return (0);
	}
	if (atoi(argv[1]) == 6)
		test_precision_printf();
	if (atoi(argv[1]) == 7)
		test_precision();
	if (atoi(argv[1]) == 8)
			test_width_printf();
	if (atoi(argv[1]) == 9)
			test_width();
	if (atoi(argv[1]) == 10)
		test_width_printf_plusminus();
	if (atoi(argv[1]) == 11)
		test_width_plusminus();
	if (atoi(argv[1]) == 12)
		test_ptr();
	if (atoi(argv[1]) == 13)
		test_width_printf_plusminussharp();
	if (atoi(argv[1]) == 14)
		test_width_plusminussharp();
	if (atoi(argv[1]) == 15)
		test_width_printf_moretest();
	if (atoi(argv[1]) == 16)
		test_width_moretest();
	if (atoi(argv[1]) == 17)
		test_special_printf();
	if (atoi(argv[1]) == 18)
		test_special();
	if (atoi(argv[1]) == 19)
		test_char_printf();
	if (atoi(argv[1]) == 20)
		test_char();
	return (0);
}
