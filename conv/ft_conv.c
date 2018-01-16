/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 10:29:20 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/16 09:21:08 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_conv(t_parsed_opt *opt, va_list curr_arg)
{
	if (ft_strchr("oOxXdupi", opt->ch_convert))
		ft_conv_integer(opt, curr_arg);
	ft_printf_manage_flag(opt);
	ft_printf_precision(opt);
	ft_printf_width(opt);
	if (opt->ch_convert == 'X')
		ft_strupcase(opt->str_arg);
	return (0);
}
