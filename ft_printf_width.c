/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlulu <tomlulu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 14:39:10 by tomlulu           #+#    #+#             */
/*   Updated: 2018/01/18 11:58:47 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_width(t_parsed_opt *opt)
{
	char *temp;

	if (opt->bin_flag & FLG_ZERO && opt->in_precision == -1)
	{
		if (opt->str_arg[0] == '+' || opt->str_arg[0] == '-')
		{
			opt->in_precision = opt->in_width - 1;
			opt->in_width = 0;
			ft_printf_precision(opt);
		}
		else if (opt->in_precision == -1 && (opt->bin_flag & FLG_ZERO) && ft_strcmp("0", opt->str_arg) == 0)
		{
			;
		}
		else
		{
			opt->in_precision = opt->in_width;
			opt->in_width = 0;
			ft_printf_precision(opt);
		}
	}
	while (ft_strlen(opt->str_arg) < (size_t)opt->in_width)
	{
		temp = opt->str_arg;
		if (opt->bin_flag & FLG_MINUS)
		{
			opt->str_arg = ft_strjoin(opt->str_arg, " ");
			free(temp);
		}
		else
		{
			opt->str_arg = ft_strjoin(" ", opt->str_arg);
			free(temp);
		}
	}
}
