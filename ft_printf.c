/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 10:57:07 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/09 19:53:53 by tomlulu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	ft_printf(const char *format, ...)
{
	va_list arg;
	char	*p_format;
	t_parsed_opt opt;
	int ret;

	va_start(arg, format);
	p_format = (char *)format;
	ret = 0;
	while (*p_format)
	{
		if (*p_format == '%')
		{
			ft_parser_init_t_parsed_opt(&opt);
			ret = ret + ft_parser(&opt, &p_format);
			ft_printf_print_opt(opt);
		}
		else
		{
			ft_putchar(*p_format);
			ret++;
			p_format++;
		}

	}
	va_end(arg);
	return (ret);
}

int		main(void)
{
	int ret;

	ret = ft_printf("test%test%2$#+0 -d\n");
	return (ret);
}
