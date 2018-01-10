/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 10:57:07 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/10 17:31:46 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_print_until_perc(char **format)
{
	char	*begin;
	int		len;

	len = 0;
	begin = *format;
	if (!(**format) || **format == '%')
		return (0);
	while (*++begin != '%' && *begin)
		len++;
	write(1, *format, len + 1);
	*format = begin;
	return (len + 1);
}

int 	ft_printf(const char *format, ...)
{
	va_list			arg;
	va_list			arg_start;
	char			*p_format;
	t_parsed_opt	opt;
	int 			ret;

	va_start(arg, format);
	va_copy(arg_start, arg);
	p_format = (char *)format;
	ret = 0;
	while (*p_format)
	{
		ret += ft_printf_print_until_perc(&p_format);
		if (*p_format == '%')
		{
			ft_parser_init_t_parsed_opt(&opt);
			ret += ft_parser(&opt, &p_format, arg, arg_start);
			ft_printf_print_opt(opt);
		}
	}
	va_end(arg);
	return (ret);
}

int		main(void)
{
	int ret;
	ret = ft_printf("%*1$d ojefoejfoejfjo %*1$d\n", 10, 15, 16);
//	ret = ft_printf("1234%%56789");
//	printf("|%d|\n", ret);
	ret = 0;
	return (ret);
}
