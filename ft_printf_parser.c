/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlulu <tomlulu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:10:56 by tomlulu           #+#    #+#             */
/*   Updated: 2018/01/11 15:08:35 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parser_init_t_parsed_opt(t_parsed_opt *opt)
{
	opt->bin_flag = 0;
	opt->in_width = 0;
	opt->in_precision = 0;
	opt->bin_lenmod = 0;
	opt->ch_convert = 0;
	opt->in_argnbr = 0;
	opt->in_base = 0;
}

void	ft_parser_manage_base(t_parsed_opt *opt)
{
	opt->in_base = 0;
	opt->in_base = opt->ch_convert == 'd' ? 10 : opt->in_base;
	opt->in_base = opt->ch_convert == 'i' ? 10 : opt->in_base;
	opt->in_base = opt->ch_convert == 'u' ? 10 : opt->in_base;
	opt->in_base = opt->ch_convert == 'p' ? 16 : opt->in_base;
	opt->in_base = opt->ch_convert == 'o' ? 8 : opt->in_base;
	opt->in_base = opt->ch_convert == 'O' ? 8 : opt->in_base;
	opt->in_base = opt->ch_convert == 'x' ? 8 : opt->in_base;
	opt->in_base = opt->ch_convert == 'X' ? 16 : opt->in_base;
}
void	ft_parser_manage_prec(char **format, t_parsed_opt *opt)
{
	int nbr;

	nbr = 0;
	if (**format == '.')
	{
		(*format)++;
		nbr = ft_parser_read_int_upd_str(format);
		opt->in_precision = nbr;
	}
}

int		ft_parser_manage_lenmod(char **format, t_parsed_opt *opt)
{
	while (**format && ft_strchr(AVAILABLE_LENMOD, **format))
	{
		if (**format == 'h')
		{
			if (opt->bin_lenmod & LENMOD_H)
				opt->bin_lenmod = LENMOD_HH;
			else
				opt->bin_lenmod = LENMOD_H;
		}
		if (**format == 'l')
		{
			if (opt->bin_lenmod & LENMOD_L)
				opt->bin_lenmod = LENMOD_LL;
			else
				opt->bin_lenmod = LENMOD_L;
		}
		if (**format == 'j')
			opt->bin_lenmod = LENMOD_J;
		if (**format == 'z')
			opt->bin_lenmod = LENMOD_Z;
		(*format)++;
	}
	return (0);
}

int		ft_parser(t_parsed_opt *opt, char **format,
va_list curr_arg, va_list start_arg)
{
	char	*begin;

	begin = *format;
	if (ft_parser_managepercent(format) == 1)
		return (1);
	(*format)++;
	begin = *format;
//	printf("\n++++|%c|+++++ %d %s\n", *begin, __LINE__, __FILE__);
	ft_parser_manage_argnbr(format, begin, opt);
//	printf("\n++++|%c|+++++ %d %s\n", **format, __LINE__, __FILE__);
	ft_parser_manage_flag(format, opt);
//	printf("\n++++|%c|+++++ %d %s\n", **format, __LINE__, __FILE__);
	ft_parser_manage_width(format, opt);
	ft_parser_manage_prec(format, opt);
	ft_parser_manage_lenmod(format, opt);
	if (ft_strchr(AVAILABLE_CONV, **format))
	{
		opt->ch_convert = **format;
		(*format)++;
	}
	else
		opt->ch_convert = -1;
	ft_parser_manage_base(opt);
	ft_conv(opt, curr_arg);
	if (start_arg)
		;
	return (0);
}
