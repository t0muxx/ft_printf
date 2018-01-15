/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:58:00 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/15 17:07:32 by tmaraval         ###   ########.fr       */
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
		printf("|%2.0lx|\n", 0);
		ft_printf("|%2.0lx|\n", 0);
		printf("|%#-2.0lx|\n", 0);
		ft_printf("|%#-2.0lx|\n", 0);
		printf("|%#-2.0i|\n", 0);
		ft_printf("|%#-2.0i|\n", 0);
		printf("|%#-2.0d|\n", 0);
		ft_printf("|%#-2.0d|\n", 0);
		printf("|%-2.0hho|\n", 0);
		ft_printf("|%-2.0hho|\n", 0);
		printf("|%#-2.0o|\n", 0);
		ft_printf("|%#-2.0o|\n", 0);
		printf("|%#-2.0lx|\n", 0);
		ft_printf("|%#-2.0lx|\n", 0);
		printf("|%#-2.0i|\n", 0);
		ft_printf("|%#-2.0i|\n", 0);
		printf("|%#-2.0d|\n", 0);
		ft_printf("|%#-2.0d|\n", 0);
		printf("|%-2.0hho|\n", 0);
		ft_printf("|%-2.0hho|\n", 0);
		printf("|%d|\n", 0);
		ft_printf("|%d|\n", 0);

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
	return (0);
}
