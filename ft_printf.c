/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 10:57:07 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/15 08:45:03 by tmaraval         ###   ########.fr       */
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
	char			*p_format;
	t_parsed_opt	opt;
	int 			ret;

	va_start(curr_arg, format);
	p_format = (char *)format;
	ret = 0;
	while (*p_format)
	{
//		va_copy(start_arg, first_arg);
		ret += ft_printf_print_until_perc(&p_format);
		if (*p_format == '%')
		{
			ft_parser_init_t_parsed_opt(&opt);
			ret += ft_parser(&opt, &p_format, curr_arg);
			//ft_printf_print_opt(opt);
		}
	}
	va_end(curr_arg);
	return (ret);
}
