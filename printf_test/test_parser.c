/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:24:09 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/14 14:53:27 by tomlulu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "printf_test.h"

int 	ft_printf(const char *format, ...);

void	test_conv_init_str(char *str)
{
	char *flag = AVAILABLE_FLAG;
	char *lenmod = AVAILABLE_LENMOD;
	int random_flg;
	int random_lenmod;
	int	random_width;
	int random_prec;

	ft_bzero(str, 1000);
	ft_strcpy(str, "%");
	srand(time(NULL));
	random_flg = rand()%4+0;
	random_lenmod = rand()%3+0;
	random_width = rand()%100+2;
	random_prec = rand()%100+2;
	ft_strncat(str, flag + random_flg, 1);
	ft_strcat(str, ft_itoa_base(random_width, 10));
	ft_strcat(str, ".");
	ft_strcat(str, ft_itoa_base(random_prec, 10));
	ft_strncat(str, lenmod + random_lenmod, 1);
}

void	test_conv()
{
	char str[1000];
	int i = 0;
	int j = 10;

	char *converter = AVAILABLE_CONV;
	while (j > 0)
	{
		i = 0;
		while (converter[i])
		{
			test_conv_init_str(str);
			ft_strncat(str, converter + i, 1);
			i++;
			ft_putendl(str);
			ft_printf(str);
			sleep(1);
		}
		j--;
	}
}

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

void	test_fuzz_opt()
{
	ft_printf("abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)abcdefghijklmnopqrstuvxyz123456789!@#$(_+)\n");
}
