/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 10:57:07 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/11 16:31:25 by tmaraval         ###   ########.fr       */
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
	va_list			curr_arg;
	va_list			first_arg;
	va_list			start_arg;
	char			*p_format;
	t_parsed_opt	opt;
	int 			ret;

	va_start(first_arg, format);
	va_copy(curr_arg, first_arg);
	p_format = (char *)format;
	ret = 0;
	while (*p_format)
	{
//		va_copy(start_arg, first_arg);
		ret += ft_printf_print_until_perc(&p_format);
		if (*p_format == '%')
		{
			ft_parser_init_t_parsed_opt(&opt);
			ret += ft_parser(&opt, &p_format, curr_arg, start_arg);
			ft_printf_print_opt(opt);
		}
	}
	va_end(first_arg);
	va_end(curr_arg);
	va_end(start_arg);
	return (ret);
}

int		main(void)
{
	int ret;

	int *ptr;
	int rptr;
	rptr = 10;
	ptr = &rptr;

	ret = ft_printf("%u\n", -83648);
	printf("%u\n", -83648);
//	ret = ft_printf("1234%%56789");
	ret = 0;
	return (ret);
}
