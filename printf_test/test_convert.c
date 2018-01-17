/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 09:39:16 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/17 09:30:33 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr(char const *s)
{
	write(1, s, ft_strlen(s));
}

void	ft_putendl(char const *s)
{
	ft_putstr(s);
	write(1, "\n", 1);
}

void	ft_putnbr(int n)
{
	long nb;

	nb = (long)n;
	if (nb < 0)
	{
		nb = nb * -1;
		ft_putchar('-');
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	ft_putchar(nb % 10 + '0');
}

void	test_char_printf()
{
	printf("|%c|\n", 'a');
	printf("|%5c|\n", 'b');
	printf("|%-5c|\n", 'c');
	printf("|%05c|\n", 'd');
	printf("|%05.5c|\n", 'e');
	printf("|%05.5c|\n", 265);
	printf("|%lc|\n", 137);
	printf("|%s|\n", "test");
	printf("|%s|\n", "");
	printf("|%09s|\n", "test");
	printf("|%-9s|\n", "test");
	printf("|%-09s|\n", "test");
	printf("|% 9s|\n", "test");
	printf("|%.2s|\n", "test");
	printf("|%9.2s|\n", "test");
	printf("|%-9.2s|\n", "test");
	printf("|%ls|\n", L"tést");
	printf("|%-6ls|\n", L"tést");
	printf("|%6ls|\n", L"tést");
	printf("|%.2S|\n", L"tést\0");
}

void	test_char()
{

	ft_printf("|%c|\n", 'a');
	ft_printf("|%5c|\n", 'b');
	ft_printf("|%-5c|\n", 'c');
	ft_printf("|%05c|\n", 'd');
	ft_printf("|%05.5c|\n", 'e');
	ft_printf("|%05.5c|\n", 265);
	ft_printf("|%lc|\n", 137);
	ft_printf("|%s|\n", "test");
	ft_printf("|%s|\n", "");
	ft_printf("|%09s|\n", "test");
	ft_printf("|%-9s|\n", "test");
	ft_printf("|%-09s|\n", "test");
	ft_printf("|% 9s|\n", "test");
	ft_printf("|%.2s|\n", "test");
	ft_printf("|%9.2s|\n", "test");
	ft_printf("|%-9.2s|\n", "test");
	ft_printf("|%ls|\n", L"tést");
	ft_printf("|%-6ls|\n", L"tést");
	ft_printf("|%6ls|\n", L"tést");
	ft_printf("|%.2S|\n", L"tést\0");
}

void	test_special_printf()
{
	printf("|%04i|\n", 43);
	printf("|%05i|\n", 43);
	printf("|%04i|\n", -43);
	printf("|%+05i|\n", 43);
	printf("oooooo |%+04i|\n", -42);
	printf("oooooo |%+04d|\n", 42);
	printf("|%p|\n", 0);
	printf("|%x|\n", 0);
	printf("salut |%d| ceci est un |% 09i| test |%+ 8u| ouloulou\n", 1567, -9874, -94);
}

void	test_special()
{
	ft_printf("|%04i|\n", 43);
	ft_printf("|%05i|\n", 43);
	ft_printf("|%04i|\n", -43);
	ft_printf("|%+05i|\n", 43);
	ft_printf("oooooo |%+04i|\n", -42);
	ft_printf("oooooo |%+04d|\n", 42);
	ft_printf("|%p|\n", 0);
	ft_printf("|%x|\n", 0);
	ft_printf("salut |%d| ceci est un |% 09i| test |%+ 8u| ouloulou\n", 1567, -9874, -94);
}

void	test_width_printf_moretest()
{
	long long tab[16] = {-128, 127, 0, 255, -32768, 32767, 0, 65535,
	-2147483648, 2147483647, 0, 4294967295, -9223372036854775807, 9223372036854775807,0, 18446744073709551615 };
	int i;
	int j;
	char tab2[48][4] = {"2", "3", "4", "2", "3", "4", "0", "1", "2", "2", "3", "4", "4", "5", "6", "4", "5", "6", "0", "0", "1", "4", "5", "6", "9", "10", "11", "9", "10", "11",
		"0", "0", "1", "9", "10", "11", "18", "19", "20", "18", "19", "20", "20", "21", "22"};
	char tabwidth[48][4] = {"4", "5", "6", "4", "5", "6", "2", "3", "4", "4", "5", "6", "6", "7", "8", "6", "7", "8", "2", "2", "3", "6", "7", "8", "11", "12", "13", "11", "12", "13",
		"2", "2", "3", "11", "12", "13", "20", "21", "22", "20", "21", "22", "22", "23", "23"};
	char tab3[35][6] = {"d", "hd", "hhd", "ld", "lld", "jd", "zd", "i", "hi", "hhi", "li", "lli", "ji", "zi",
	"u", "hu", "hhu", "lu", "llu", "ju", "zu", "o", "ho", "hho", "lo", "llo", "jo", "zo",
	"x", "hx", "hhx", "lx", "llx", "jx", "zx" };
	i = 0;
	j = 0;
	int k;
	k = 0;
	char str[100];
	while (j < 45)
	{
		i = 0;
		while (i < 16)
		{
			printf("i = %d\n", i);
			printf("j = %d\n", j);
			k = 0;
			while (k < 35)
			{
				bzero(str, 100);
				strcat(str, "% #-0");
				strcat(str, tabwidth[j]);
				strcat(str, ".");
				strcat(str, tab2[j]);
				strcat(str, tab3[k]);
				strcat(str, "\n");
				strcat(str, "%-+");
				strcat(str, tabwidth[j]);
				strcat(str, ".");
				strcat(str, tab2[j]);
				strcat(str, tab3[k]);
				strcat(str, "   ");
				strcat(str, "%-+#");
				strcat(str, tabwidth[j]);
				strcat(str, ".");
				strcat(str, tab2[j]);
				strcat(str, tab3[k]);
				strcat(str, "\n");
				printf("%s", str);
				printf(str, tab[i], tab[i], tab[i]);
				k++;
			}
			i++;
		}
		j++;
	}
}

void	test_width_moretest()
{
	long long tab[16] = {-128, 127, 0, 255, -32768, 32767, 0, 65535,
	-2147483648, 2147483647, 0, 4294967295, -9223372036854775807, 9223372036854775807,0, 18446744073709551615 };
	int i;
	int j;
	char tab2[48][4] = {"2", "3", "4", "2", "3", "4", "0", "1", "2", "2", "3", "4", "4", "5", "6", "4", "5", "6", "0", "0", "1", "4", "5", "6", "9", "10", "11", "9", "10", "11",
		"0", "0", "1", "9", "10", "11", "18", "19", "20", "18", "19", "20", "20", "21", "22"};
	char tabwidth[48][4] = {"4", "5", "6", "4", "5", "6", "2", "3", "4", "4", "5", "6", "6", "7", "8", "6", "7", "8", "2", "2", "3", "6", "7", "8", "11", "12", "13", "11", "12", "13",
		"2", "2", "3", "11", "12", "13", "20", "21", "22", "20", "21", "22", "22", "23", "23"};
	char tab3[35][6] = {"d", "hd", "hhd", "ld", "lld", "jd", "zd", "i", "hi", "hhi", "li", "lli", "ji", "zi",
	"u", "hu", "hhu", "lu", "llu", "ju", "zu", "o", "ho", "hho", "lo", "llo", "jo", "zo",
	"x", "hx", "hhx", "lx", "llx", "jx", "zx" };
	i = 0;
	j = 0;
	int k;
	k = 0;
	char str[100];
	while (j < 45)
	{
		i = 0;
		while (i < 16)
		{
			ft_putstr("i = ");
			ft_putnbr(i);
			ft_putendl("");
			ft_putstr("j = ");
			ft_putnbr(j);
			ft_putendl("");
			k = 0;
			while (k < 35)
			{
				bzero(str, 100);
				strcat(str, "% #-0");
				strcat(str, tabwidth[j]);
				strcat(str, ".");
				strcat(str, tab2[j]);
				strcat(str, tab3[k]);
				strcat(str, "\n");
				strcat(str, "%-+");
				strcat(str, tabwidth[j]);
				strcat(str, ".");
				strcat(str, tab2[j]);
				strcat(str, tab3[k]);
				strcat(str, "   ");
				strcat(str, "%-+#");
				strcat(str, tabwidth[j]);
				strcat(str, ".");
				strcat(str, tab2[j]);
				strcat(str, tab3[k]);
				strcat(str, "\n");
				ft_putstr(str);
				ft_printf(str, tab[i], tab[i], tab[i]);
				k++;
			}
			i++;
		}
		j++;
	}
}

void	test_width_printf_plusminussharp()
{
	long long tab[16] = {-128, 127, 0, 255, -32768, 32767, 0, 65535,
	-2147483648, 2147483647, 0, 4294967295, -9223372036854775807, 9223372036854775807,0, 18446744073709551615 };
	int i;
	int j;
	char tab2[48][4] = {"2", "3", "4", "2", "3", "4", "0", "1", "2", "2", "3", "4", "4", "5", "6", "4", "5", "6", "0", "0", "1", "4", "5", "6", "9", "10", "11", "9", "10", "11",
		"0", "0", "1", "9", "10", "11", "18", "19", "20", "18", "19", "20", "20", "21", "22"};
	char tabwidth[48][4] = {"4", "5", "6", "4", "5", "6", "2", "3", "4", "4", "5", "6", "6", "7", "8", "6", "7", "8", "2", "2", "3", "6", "7", "8", "11", "12", "13", "11", "12", "13",
		"2", "2", "3", "11", "12", "13", "20", "21", "22", "20", "21", "22", "22", "23", "23"};
	char tab3[35][6] = {"d", "hd", "hhd", "ld", "lld", "jd", "zd", "i", "hi", "hhi", "li", "lli", "ji", "zi",
	"u", "hu", "hhu", "lu", "llu", "ju", "zu", "o", "ho", "hho", "lo", "llo", "jo", "zo",
	"x", "hx", "hhx", "lx", "llx", "jx", "zx" };
	i = 0;
	j = 0;
	int k;
	k = 0;
	char str[100];
	while (j < 45)
	{
		i = 0;
		while (i < 16)
		{
			printf("i = %d\n", i);
			printf("j = %d\n", j);
			k = 0;
			while (k < 35)
			{
				bzero(str, 100);
				strcat(str, "%#-");
				strcat(str, tabwidth[j]);
				strcat(str, ".");
				strcat(str, tab2[j]);
				strcat(str, tab3[k]);
				strcat(str, "\n");
				printf("%s", str);
				printf(str, tab[i]);
				k++;
			}
			i++;
		}
		j++;
	}
}

void	test_width_plusminussharp()
{
	long long tab[16] = {-128, 127, 0, 255, -32768, 32767, 0, 65535,
	-2147483648, 2147483647, 0, 4294967295, -9223372036854775807, 9223372036854775807,0, 18446744073709551615 };
	int i;
	int j;
	char tab2[48][4] = {"2", "3", "4", "2", "3", "4", "0", "1", "2", "2", "3", "4", "4", "5", "6", "4", "5", "6", "0", "0", "1", "4", "5", "6", "9", "10", "11", "9", "10", "11",
		"0", "0", "1", "9", "10", "11", "18", "19", "20", "18", "19", "20", "20", "21", "22"};
	char tabwidth[48][4] = {"4", "5", "6", "4", "5", "6", "2", "3", "4", "4", "5", "6", "6", "7", "8", "6", "7", "8", "2", "2", "3", "6", "7", "8", "11", "12", "13", "11", "12", "13",
		"2", "2", "3", "11", "12", "13", "20", "21", "22", "20", "21", "22", "22", "23", "23"};
	char tab3[35][6] = {"d", "hd", "hhd", "ld", "lld", "jd", "zd", "i", "hi", "hhi", "li", "lli", "ji", "zi",
	"u", "hu", "hhu", "lu", "llu", "ju", "zu", "o", "ho", "hho", "lo", "llo", "jo", "zo",
	"x", "hx", "hhx", "lx", "llx", "jx", "zx" };
	i = 0;
	j = 0;
	int k;
	k = 0;
	char str[100];
	while (j < 45)
	{
		i = 0;
		while (i < 16)
		{
			ft_putstr("i = ");
			ft_putnbr(i);
			ft_putendl("");
			ft_putstr("j = ");
			ft_putnbr(j);
			ft_putendl("");
			k = 0;
			while (k < 35)
			{
				bzero(str, 100);
				strcat(str, "%#-");
				strcat(str, tabwidth[j]);
				strcat(str, ".");
				strcat(str, tab2[j]);
				strcat(str, tab3[k]);
				strcat(str, "\n");
				ft_putstr(str);
				ft_printf(str, tab[i]);
				k++;
			}
			i++;
		}
		j++;
	}
}


void	test_ptr()
{
	char *str = "test";
	int *pintt;
	long int *plint;

	int intt = 9;
	long int lint = 16;
	pintt = &intt;
	plint = &lint;
	printf("|%p|\n", str);
	printf("|%p|\n", pintt);
	printf("|%p|\n", plint);
	ft_printf("|%p|\n", str);
	ft_printf("|%p|\n", pintt);
	ft_printf("|%p|\n", plint);
}

void	test_width_printf_plusminus()
{
	long long tab[16] = {-128, 127, 0, 255, -32768, 32767, 0, 65535,
	-2147483648, 2147483647, 0, 4294967295, -9223372036854775807, 9223372036854775807,0, 18446744073709551615 };
	int i;
	int j;
	char tab2[48][4] = {"2", "3", "4", "2", "3", "4", "0", "1", "2", "2", "3", "4", "4", "5", "6", "4", "5", "6", "0", "0", "1", "4", "5", "6", "9", "10", "11", "9", "10", "11",
		"0", "0", "1", "9", "10", "11", "18", "19", "20", "18", "19", "20", "20", "21", "22"};
	char tabwidth[48][4] = {"4", "5", "6", "4", "5", "6", "2", "3", "4", "4", "5", "6", "6", "7", "8", "6", "7", "8", "2", "2", "3", "6", "7", "8", "11", "12", "13", "11", "12", "13",
		"2", "2", "3", "11", "12", "13", "20", "21", "22", "20", "21", "22", "22", "23", "23"};
	char tab3[35][6] = {"d", "hd", "hhd", "ld", "lld", "jd", "zd", "i", "hi", "hhi", "li", "lli", "ji", "zi",
	"u", "hu", "hhu", "lu", "llu", "ju", "zu", "o", "ho", "hho", "lo", "llo", "jo", "zo",
	"x", "hx", "hhx", "lx", "llx", "jx", "zx" };
	i = 0;
	j = 0;
	int k;
	k = 0;
	char str[100];
	while (j < 45)
	{
		i = 0;
		while (i < 16)
		{
			printf("i = %d\n", i);
			printf("j = %d\n", j);
			k = 0;
			while (k < 35)
			{
				bzero(str, 100);
				strcat(str, "%-");
				strcat(str, tabwidth[j]);
				strcat(str, ".");
				strcat(str, tab2[j]);
				strcat(str, tab3[k]);
				strcat(str, "\n");
				printf("%s", str);
				printf(str, tab[i]);
				k++;
			}
			i++;
		}
		j++;
	}
}

void	test_width_plusminus()
{
	long long tab[16] = {-128, 127, 0, 255, -32768, 32767, 0, 65535,
	-2147483648, 2147483647, 0, 4294967295, -9223372036854775807, 9223372036854775807,0, 18446744073709551615 };
	int i;
	int j;
	char tab2[48][4] = {"2", "3", "4", "2", "3", "4", "0", "1", "2", "2", "3", "4", "4", "5", "6", "4", "5", "6", "0", "0", "1", "4", "5", "6", "9", "10", "11", "9", "10", "11",
		"0", "0", "1", "9", "10", "11", "18", "19", "20", "18", "19", "20", "20", "21", "22"};
	char tabwidth[48][4] = {"4", "5", "6", "4", "5", "6", "2", "3", "4", "4", "5", "6", "6", "7", "8", "6", "7", "8", "2", "2", "3", "6", "7", "8", "11", "12", "13", "11", "12", "13",
		"2", "2", "3", "11", "12", "13", "20", "21", "22", "20", "21", "22", "22", "23", "23"};
	char tab3[35][6] = {"d", "hd", "hhd", "ld", "lld", "jd", "zd", "i", "hi", "hhi", "li", "lli", "ji", "zi",
	"u", "hu", "hhu", "lu", "llu", "ju", "zu", "o", "ho", "hho", "lo", "llo", "jo", "zo",
	"x", "hx", "hhx", "lx", "llx", "jx", "zx" };
	i = 0;
	j = 0;
	int k;
	k = 0;
	char str[100];
	while (j < 45)
	{
		i = 0;
		while (i < 16)
		{
			ft_putstr("i = ");
			ft_putnbr(i);
			ft_putendl("");
			ft_putstr("j = ");
			ft_putnbr(j);
			ft_putendl("");
			k = 0;
			while (k < 35)
			{
				bzero(str, 100);
				strcat(str, "%-");
				strcat(str, tabwidth[j]);
				strcat(str, ".");
				strcat(str, tab2[j]);
				strcat(str, tab3[k]);
				strcat(str, "\n");
				ft_putstr(str);
				ft_printf(str, tab[i]);
				k++;
			}
			i++;
		}
		j++;
	}
}

void	test_width_printf()
{
	long long tab[16] = {-128, 127, 0, 255, -32768, 32767, 0, 65535,
	-2147483648, 2147483647, 0, 4294967295, -9223372036854775807, 9223372036854775807,0, 18446744073709551615 };
	int i;
	int j;
	char tab2[48][4] = {"2", "3", "4", "2", "3", "4", "0", "1", "2", "2", "3", "4", "4", "5", "6", "4", "5", "6", "0", "0", "1", "4", "5", "6", "9", "10", "11", "9", "10", "11",
		"0", "0", "1", "9", "10", "11", "18", "19", "20", "18", "19", "20", "20", "21", "22"};
	char tabwidth[48][4] = {"4", "5", "6", "4", "5", "6", "2", "3", "4", "4", "5", "6", "6", "7", "8", "6", "7", "8", "2", "2", "3", "6", "7", "8", "11", "12", "13", "11", "12", "13",
		"2", "2", "3", "11", "12", "13", "20", "21", "22", "20", "21", "22", "22", "23", "23"};
	char tab3[35][6] = {"d", "hd", "hhd", "ld", "lld", "jd", "zd", "i", "hi", "hhi", "li", "lli", "ji", "zi",
	"u", "hu", "hhu", "lu", "llu", "ju", "zu", "o", "ho", "hho", "lo", "llo", "jo", "zo",
	"x", "hx", "hhx", "lx", "llx", "jx", "zx" };
	i = 0;
	j = 0;
	int k;
	k = 0;
	char str[100];
	while (j < 45)
	{
		i = 0;
		while (i < 16)
		{
			printf("i = %d\n", i);
			printf("j = %d\n", j);
			k = 0;
			while (k < 35)
			{
				bzero(str, 100);
				strcat(str, "%");
				strcat(str, tabwidth[j]);
				strcat(str, ".");
				strcat(str, tab2[j]);
				strcat(str, tab3[k]);
				strcat(str, "\n");
				printf("%s", str);
				printf(str, tab[i]);
				k++;
			}
			i++;
		}
		j++;
	}
}

void	test_width()
{
	long long tab[16] = {-128, 127, 0, 255, -32768, 32767, 0, 65535,
	-2147483648, 2147483647, 0, 4294967295, -9223372036854775807, 9223372036854775807,0, 18446744073709551615 };
	int i;
	int j;
	char tab2[48][4] = {"2", "3", "4", "2", "3", "4", "0", "1", "2", "2", "3", "4", "4", "5", "6", "4", "5", "6", "0", "0", "1", "4", "5", "6", "9", "10", "11", "9", "10", "11",
		"0", "0", "1", "9", "10", "11", "18", "19", "20", "18", "19", "20", "20", "21", "22"};
	char tabwidth[48][4] = {"4", "5", "6", "4", "5", "6", "2", "3", "4", "4", "5", "6", "6", "7", "8", "6", "7", "8", "2", "2", "3", "6", "7", "8", "11", "12", "13", "11", "12", "13",
		"2", "2", "3", "11", "12", "13", "20", "21", "22", "20", "21", "22", "22", "23", "23"};
	char tab3[35][6] = {"d", "hd", "hhd", "ld", "lld", "jd", "zd", "i", "hi", "hhi", "li", "lli", "ji", "zi",
	"u", "hu", "hhu", "lu", "llu", "ju", "zu", "o", "ho", "hho", "lo", "llo", "jo", "zo",
	"x", "hx", "hhx", "lx", "llx", "jx", "zx" };
	i = 0;
	j = 0;
	int k;
	k = 0;
	char str[100];
	while (j < 45)
	{
		i = 0;
		while (i < 16)
		{
			ft_putstr("i = ");
			ft_putnbr(i);
			ft_putendl("");
			ft_putstr("j = ");
			ft_putnbr(j);
			ft_putendl("");
			k = 0;
			while (k < 35)
			{
				bzero(str, 100);
				strcat(str, "%");
				strcat(str, tabwidth[j]);
				strcat(str, ".");
				strcat(str, tab2[j]);
				strcat(str, tab3[k]);
				strcat(str, "\n");
				ft_putstr(str);
				ft_printf(str, tab[i]);
				k++;
			}
			i++;
		}
		j++;
	}
}

void	test_precision()
{
	long long tab[16] = {-128, 127, 0, 255, -32768, 32767, 0, 65535,
	-2147483648, 2147483647, 0, 4294967295, -9223372036854775807, 9223372036854775807,0, 18446744073709551615 };
	int i;
	int j;
	char tab2[48][4] = {"2", "3", "4", "2", "3", "4", "0", "1", "2", "2", "3", "4", "4", "5", "6", "4", "5", "6", "0", "0", "1", "4", "5", "6", "9", "10", "11", "9", "10", "11",
		"0", "0", "1", "9", "10", "11", "18", "19", "20", "18", "19", "20", "20", "21", "22"};
	char tab3[35][6] = {"d", "hd", "hhd", "ld", "lld", "jd", "zd", "i", "hi", "hhi", "li", "lli", "ji", "zi",
	"u", "hu", "hhu", "lu", "llu", "ju", "zu", "o", "ho", "hho", "lo", "llo", "jo", "zo",
	"x", "hx", "hhx", "lx", "llx", "jx", "zx" };
	i = 0;
	j = 0;
	int k;
	k = 0;
	int ret = 0;
	char str[100];
	while (j < 45)
	{
		i = 0;
		while (i < 16)
		{
			ft_putstr("i = ");
			ft_putnbr(i);
			ft_putendl("");
			ft_putstr("j = ");
			ft_putnbr(j);
			ft_putendl("");
			k = 0;
			while (k < 35)
			{
				bzero(str, 100);
				strcat(str, "%.");
				strcat(str, tab2[j]);
				strcat(str, tab3[k]);
				strcat(str, "\n");
				ret = ft_printf(str, tab[i]);
				ft_putnbr(ret);
				ft_putendl("");
				k++;
			}
			i++;
		}
		j++;
	}
}

void	test_precision_printf()
{
	long long tab[16] = {-128, 127, 0, 255, -32768, 32767, 0, 65535,
	-2147483648, 2147483647, 0, 4294967295, -9223372036854775807, 9223372036854775807,0, 18446744073709551615 };
	int i;
	int j;
	char tab2[48][4] = {"2", "3", "4", "2", "3", "4", "0", "1", "2", "2", "3", "4", "4", "5", "6", "4", "5", "6", "0", "0", "1", "4", "5", "6", "9", "10", "11", "9", "10", "11",
		"0", "0", "1", "9", "10", "11", "18", "19", "20", "18", "19", "20", "20", "21", "22"};
	char tab3[35][6] = {"d", "hd", "hhd", "ld", "lld", "jd", "zd", "i", "hi", "hhi", "li", "lli", "ji", "zi",
	"u", "hu", "hhu", "lu", "llu", "ju", "zu", "o", "ho", "hho", "lo", "llo", "jo", "zo",
	"x", "hx", "hhx", "lx", "llx", "jx", "zx" };
	i = 0;
	j = 0;
	int k;
	k = 0;
	int ret;

	ret = 0;
	char str[100];
	while (j < 45)
	{
		i = 0;
		while (i < 16)
		{
			printf("i = %d\n", i);
			printf("j = %d\n", j);
			k = 0;
			while (k < 35)
			{
				bzero(str, 100);
				strcat(str, "%.");
				strcat(str, tab2[j]);
				strcat(str, tab3[k]);
				strcat(str, "\n");
				ret = printf(str, tab[i]);
				printf("%d\n", ret);
				k++;
			}
			i++;
		}
		j++;
	}
}

void	test_convert_printf()
{
	long long tab[16] = {-128, 127, 0, 255, -32768, 32767, 0, 65535,
	-2147483648, 2147483647, 0, 4294967295, -9223372036854775807, 9223372036854775807,0, 18446744073709551615 };
	int i;

	i = 0;
	while (i < 16)
	{
		printf("i = %d\n", i);
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
		ft_putstr("i = ");
		ft_putnbr(i);
		ft_putendl("");
		ft_printf("%d\n", tab[i]);
		ft_printf("%hd\n", tab[i]);
		ft_printf("%hhd\n", tab[i]);
		ft_printf("%ld\n", tab[i]);
		ft_printf("%lld\n", tab[i]);
		ft_printf("%jd\n", tab[i]);
		ft_printf("%zd\n", tab[i]);
		ft_printf("%i\n", tab[i]);
		ft_printf("%hi\n", tab[i]);
		ft_printf("%hhi\n", tab[i]);
		ft_printf("%li\n", tab[i]);
		ft_printf("%lli\n", tab[i]);
		ft_printf("%ji\n", tab[i]);
		ft_printf("%zi\n", tab[i]);
		ft_printf("%u\n", tab[i]);
		ft_printf("%hu\n", tab[i]);
		ft_printf("%hhu\n", tab[i]);
		ft_printf("%lu\n", tab[i]);
		ft_printf("%llu\n", tab[i]);
		ft_printf("%ju\n", tab[i]);
		ft_printf("%zu\n", tab[i]);
		ft_printf("%o\n", tab[i]);
		ft_printf("%ho\n", tab[i]);
		ft_printf("%hho\n", tab[i]);
		ft_printf("%lo\n", tab[i]);
		ft_printf("%llo\n", tab[i]);
		ft_printf("%jo\n", tab[i]);
		ft_printf("%zo\n", tab[i]);
		ft_printf("%x\n", tab[i]);
		ft_printf("%hx\n", tab[i]);
		ft_printf("%hhx\n", tab[i]);
		ft_printf("%lx\n", tab[i]);
		ft_printf("%llx\n", tab[i]);
		ft_printf("%jx\n", tab[i]);
		ft_printf("%zx\n", tab[i]);
		i++;
	}
}
