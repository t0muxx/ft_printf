/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlulu <tomlulu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:10:56 by tomlulu           #+#    #+#             */
/*   Updated: 2018/01/09 21:53:10 by tomlulu          ###   ########.fr       */
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

	begin = format;
	if (ft_parser_managepercent(format) == 1)
		return (1);
	(*format)++;
	ft_parser_manage_argnbr(format, begin, opt);
//	printf("\n|%c|\n", **format);
	ft_parser_manage_flag(format, opt);
	opt = opt;
	return (0);
}
