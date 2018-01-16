/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:58:00 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/16 15:21:10 by tmaraval         ###   ########.fr       */
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
		printf("|%c|\n", 'a');
		ft_printf("|%c|\n", 'a');
		printf("|%5c|\n", 'b');
		ft_printf("|%5c|\n", 'b');
		printf("|%-5c|\n", 'c');
		ft_printf("|%-5c|\n", 'c');
		printf("|%05c|\n", 'd');
		ft_printf("|%05c|\n", 'd');
		printf("|%05.5c|\n", 'e');
		ft_printf("|%05.5c|\n", 'e');
		printf("|%lc|\n", 137);
		ft_printf("|%lc|\n", 137);
		printf("|%05d|\n", 100);
		ft_printf("|%05d|\n", 100);
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
	return (0);
}
