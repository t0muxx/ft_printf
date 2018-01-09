/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlulu <tomlulu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 16:27:58 by tomlulu           #+#    #+#             */
/*   Updated: 2018/01/09 21:52:46 by tomlulu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parser_managepercent(char **format)
{
	char *begin;

	begin = *format;
	begin++;
	if (*begin == '%')
	{
		(*format)++;
		(*format)++;
		ft_putchar('%');
		return (1);
	}
	return (0);
}

int		ft_parser_read_int_upd_str(char **format)
{
	int ret;

	ret = **format - '0';
	(*format)++;
	while (ft_isdigit(**format))
	{
		if (ret > INT_MAX)
			ret = -1;
		else
		{
			ret *= 10;
			ret += **format - '0';
		}
		(*format)++;
	}
	return (ret);
}

void	ft_parser_manage_argnbr(char **format, char **begin, t_parsed_opt *opt)
{
	int nbr;

	nbr = 0;
	if (ft_isdigit(**format))
	{
		nbr = ft_parser_read_int_upd_str(format);
		if (**format == '$')
		{
			opt->in_argnbr = nbr;
			(*format)++;
		}
		else
			format = begin;
	}
}

void	ft_parser_manage_flag(char **format, t_parsed_opt *opt)
{
	while (ft_strchr(AVAILABLE_FLAG, **format) && **format)
	{
		opt->bin_flag |= **format == '#' ? FLG_SHARP : 0;
		opt->bin_flag |= **format == '0' ? FLG_ZERO : 0;
		opt->bin_flag |= **format == '-' ? FLG_MINUS : 0;
		opt->bin_flag |= **format == ' ' ? FLG_SP : 0;
		opt->bin_flag |= **format == '+' ? FLG_PLUS : 0;
		(*format)++;
	}
}
