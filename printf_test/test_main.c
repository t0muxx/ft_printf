/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:58:00 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/16 16:34:38 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_test.h"

int	main(int argc, char **argv)
{
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
		printf("|%s|\n", "test");
		ft_printf("|%s|\n", "test");
		printf("|%s|\n", "");
		ft_printf("|%s|\n", "");
		printf("|%09s|\n", "test");
		ft_printf("|%09s|\n", "test");
		printf("|%-9s|\n", "test");
		ft_printf("|%-9s|\n", "test");
		printf("|%-09s|\n", "test");
		ft_printf("|%-09s|\n", "test");
		printf("|% 9s|\n", "test");
		ft_printf("|% 9s|\n", "test");
		printf("|%.2s|\n", "test");
		ft_printf("|%.2s|\n", "test");
		printf("|%9.2s|\n", "test");
		ft_printf("|%9.2s|\n", "test");
		printf("|%-9.2s|\n", "test");
		ft_printf("|%-9.2s|\n", "test");
		printf("|%ls|\n", L"tést");
		ft_printf("|%ls|\n", L"tést");
		printf("|%S|\n", L"tést");
		ft_printf("|%S|\n", L"tést");

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
