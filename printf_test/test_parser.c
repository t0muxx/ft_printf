/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:24:09 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/10 20:46:53 by tomlulu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "printf_test.h"

int 	ft_printf(const char *format, ...);

void	test_big_width_prec_argnbr()
{
	printf("TEST 1\n");
	ft_printf("%2147483646$2147483646.2147483646d");
	ft_printf("%2147483646$-2147483646.2147483646d");
	ft_printf("%2147483646$02147483646.2147483646d");
	ft_printf("%2147483646$ 2147483646.2147483646d");
	printf("TEST 2\n");
	ft_printf("%2147483647$2147483647.2147483647d");
	ft_printf("%2147483647$-2147483647.2147483647d");
	ft_printf("%2147483647$02147483647.2147483647d");
	ft_printf("%2147483647$ 2147483647.2147483647d");
	printf("TEST 3\n");
	ft_printf("%2147483648$2147483648.2147483648d");
	ft_printf("%2147483648$-2147483648.2147483648d");
	ft_printf("%2147483648$02147483648.2147483648d");
	ft_printf("%2147483648$ 2147483648.2147483648d");
	printf("TEST 4\n");
	ft_printf("%2147483649$2147483649.2147483649d");
	ft_printf("%2147483649$-2147483649.2147483649d");
	ft_printf("%2147483649$02147483649.2147483649d");
	ft_printf("%2147483649$ 2147483649.2147483649d");
	printf("TEST 5\n");
	ft_printf("%-2147483649$-2147483649.-2147483649d");
	ft_printf("%-2147483649$-2147483649.-2147483649d");
	ft_printf("%-2147483649$0-2147483649.-2147483649d");
	ft_printf("%-2147483649$ -2147483649.-2147483649d");
	printf("TEST 6\n");
	ft_printf("%-21474836$-21474836.-21474836d");
	ft_printf("%-21474836$-21474836.-21474836d");
	ft_printf("%-21474836$0-21474836.-21474836d");
	ft_printf("%-2$ -21474836.-21474836d");
}

void	test_fuzz_opt(int looptime)
{
	char str[1000];
	char *opt;
	int j;

	j = 0;
	opt = ft_memalloc(6);
	ft_bzero(opt, 6);
	ft_bzero(str, 1000);
	ft_strcpy(opt, AVAILABLE_LENMOD);
	while (*opt)
	{
		j = 0;
		ft_bzero(str, 1000);
		ft_strcpy(str, "%");
		while (j < looptime)
		{
			ft_strncat(str, opt, 1);
			ft_printf(str);
			j++;
		}
		opt++;
	}
	opt = NULL;
	opt = ft_memalloc(6);
	ft_bzero(opt, 6);
	ft_bzero(str, 1000);
	ft_strcpy(opt, AVAILABLE_FLAG);
	while (*opt)
	{
		j = 0;
		ft_bzero(str, 1000);
		ft_strcpy(str, "%");
		while (j < looptime)
		{
			ft_strncat(str, opt, 1);
			ft_printf(str);
			j++;
		}
		opt++;
	}
	opt = NULL;
	opt = ft_memalloc(6);
	ft_bzero(opt, 6);
	ft_bzero(str, 1000);
	ft_strcpy(opt, AVAILABLE_CONV);
	while (*opt)
	{
		j = 0;
		ft_bzero(str, 1000);
		ft_strcpy(str, "%");
		while (j < looptime)
		{
			ft_strncat(str, opt, 1);
			ft_printf(str);
			j++;
		}
		opt++;
	}
}
