/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 09:39:16 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/12 10:57:24 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	test_convert_printf()
{
	long long tab[16] = {-128, 127, 0, 255, -32768, 32767, 0, 65535,
	-2147483648, 2147483647, 0, 4294967295, -9223372036854775807, 9223372036854775807,0, 18446744073709551615 };
	int i;

	i = 0;
	while (i < 16)
	{
		printf("%d\n", tab[i]);
		printf("%hd\n", tab[i]);
		printf("%hhd\n", tab[i]);
		printf("%ld\n", tab[i]);
		printf("%lld\n", tab[i]);
		printf("%jd\n", tab[i]);
		printf("%zd\n", tab[i]);
		printf("%i\n", tab[i]);
		printf("%hi\n", tab[i]);
		printf("%hhi\n", tab[i]);
		printf("%li\n", tab[i]);
		printf("%lli\n", tab[i]);
		printf("%ji\n", tab[i]);
		printf("%zi\n", tab[i]);
		printf("%u\n", tab[i]);
		printf("%hu\n", tab[i]);
		printf("%hhu\n", tab[i]);
		printf("%lu\n", tab[i]);
		printf("%llu\n", tab[i]);
		printf("%ju\n", tab[i]);
		printf("%zu\n", tab[i]);
		printf("%o\n", tab[i]);
		printf("%ho\n", tab[i]);
		printf("%hho\n", tab[i]);
		printf("%lo\n", tab[i]);
		printf("%llo\n", tab[i]);
		printf("%jo\n", tab[i]);
		printf("%zo\n", tab[i]);
		printf("%x\n", tab[i]);
		printf("%hx\n", tab[i]);
		printf("%hhx\n", tab[i]);
		printf("%lx\n", tab[i]);
		printf("%llx\n", tab[i]);
		printf("%jx\n", tab[i]);
		printf("%zx\n", tab[i]);
		i++;
	}
}

void	test_convert()
{
	long long tab[16] = {-128, 127, 0, 255, -32768, 32767, 0, 65535,
	-2147483648, 2147483647, 0, 4294967295, -9223372036854775807, 9223372036854775807,0, 18446744073709551615 };
	int i;

	i = 0;
	while (i < 16)
	{
		printf("%d\n", tab[i]);
		printf("%hd\n", tab[i]);
		printf("%hhd\n", tab[i]);
		printf("%ld\n", tab[i]);
		printf("%lld\n", tab[i]);
		printf("%jd\n", tab[i]);
		printf("%zd\n", tab[i]);
		printf("%i\n", tab[i]);
		printf("%hi\n", tab[i]);
		printf("%hhi\n", tab[i]);
		printf("%li\n", tab[i]);
		printf("%lli\n", tab[i]);
		printf("%ji\n", tab[i]);
		printf("%zi\n", tab[i]);
		printf("%u\n", tab[i]);
		printf("%hu\n", tab[i]);
		printf("%hhu\n", tab[i]);
		printf("%lu\n", tab[i]);
		printf("%llu\n", tab[i]);
		printf("%ju\n", tab[i]);
		printf("%zu\n", tab[i]);
		printf("%o\n", tab[i]);
		printf("%ho\n", tab[i]);
		printf("%hho\n", tab[i]);
		printf("%lo\n", tab[i]);
		printf("%llo\n", tab[i]);
		printf("%jo\n", tab[i]);
		printf("%zo\n", tab[i]);
		printf("%x\n", tab[i]);
		printf("%hx\n", tab[i]);
		printf("%hhx\n", tab[i]);
		printf("%lx\n", tab[i]);
		printf("%llx\n", tab[i]);
		printf("%jx\n", tab[i]);
		printf("%zx\n", tab[i]);
		i++;
	}
}
