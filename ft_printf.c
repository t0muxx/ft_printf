/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 10:57:07 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/09 17:35:32 by tomlulu          ###   ########.fr       */
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
		}
		else
		{
			ft_putchar(*p_format);
			ret++;
			p_format++;
		}

	}
	va_end(arg);
	if (opt.bin_flag & FLG_SHARP)
	{
		printf("\nflag # trouve\n");
	}
	if (opt.bin_flag & FLG_ZERO)
	{
		printf("\nflag 0 trouve\n");
	}
	if (opt.bin_flag & FLG_MINUS)
	{
		printf("\nflag - trouve\n");
	}
	if (opt.bin_flag & FLG_SP)
	{
		printf("\nflag   trouve\n");
	}
	if (opt.bin_flag & FLG_PLUS)
	{
		printf("\nflag + trouve\n");
	}
	return (ret);
}

int		main(void)
{
	int ret;

	ret = ft_printf("test%test%#\n");
	printf("%0+9d", 10);
	return (ret);
}
