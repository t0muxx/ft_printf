/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlulu <tomlulu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:10:56 by tomlulu           #+#    #+#             */
/*   Updated: 2018/01/09 17:35:33 by tomlulu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parser_init_t_parsed_opt(t_parsed_opt *opt)
{
	opt->bin_flag = 0;
	opt->in_width = 0;
	opt->in_precision = 0;
	opt->pch_lengthmod[0] = 0;
	opt->pch_lengthmod[1] = 0;
	opt->pch_lengthmod[2] = 0;
	opt->ch_convert = 0;
	opt->in_argnbr = 0;
}

int		ft_parser(t_parsed_opt *opt, char **format)
{
	char	**begin;
	int		nbr;

	nbr = 0;
	begin = format;
	if (ft_parser_managepercent(format) == 1)
		return (1);
	(*format)++;
	if (ft_isdigit(**format))
	{
		nbr = ft_parser_read_int_upd_str(format);
		if (**format == '$')
			opt->in_argnbr = nbr;
		else
			format = begin;
	}
	printf("|%c|\n", **format);
	while (**format)
	{
		if (**format == '#')
			opt->bin_flag |= FLG_SHARP;
		else if (**format == '0')
			opt->bin_flag |= FLG_ZERO;
		else if (**format == '-')
			opt->bin_flag |= FLG_MINUS;
		else if (**format == ' ')
			opt->bin_flag |= FLG_SP;
		else if (**format == '+')
			opt->bin_flag |= FLG_PLUS;
		else
			return(0);
		(*format)++;
	}
	opt = opt;
	return (0);
}