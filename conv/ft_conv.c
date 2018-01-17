/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 10:29:20 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/17 08:56:08 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_conv(t_parsed_opt *opt, va_list curr_arg)
{
	int i;

	i = 0;
	if (ft_strchr("oOxXdDupi", opt->ch_convert))
	{
		ft_conv_integer(opt, curr_arg);
		ft_printf_num_manage_flag(opt);
		ft_printf_precision(opt);
		ft_printf_width(opt);
		if (opt->ch_convert == 'X')
			ft_strupcase(opt->str_arg);
	}
	if (ft_strchr("cC", opt->ch_convert))
	{
		ft_conv_char(opt, curr_arg);
		ft_printf_cwidth(opt);
	}
	if (ft_strchr("s", opt->ch_convert) && ((opt->bin_lenmod & LENMOD_L) == 0))
	{
		ft_conv_str(opt, curr_arg);
		ft_printf_str_precision(opt);
		ft_printf_cwidth(opt);
	}
	if (opt->ch_convert == 'S' || (opt->ch_convert == 's' && opt->bin_lenmod & LENMOD_L))
	{
		ft_conv_str(opt, curr_arg);
		ft_printf_wcstr_precision(opt);
		ft_printf_wcstr_width(opt);
		while (opt->wstr_arg[i])
		{
			write(1, &opt->wstr_arg[i], 1);
			i++;
		}
	}
	return (0);
}
