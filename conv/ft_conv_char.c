/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:11:08 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/18 09:03:48 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_conv_char(t_parsed_opt *opt, va_list curr_arg)
{
	opt->str_arg = ft_memalloc(2);
	ft_bzero(opt->str_arg, 2);
	if (opt->bin_lenmod & LENMOD_L || opt->ch_convert == 'C')
		opt->str_arg[0] = (char)va_arg(curr_arg, wchar_t);
	else if (opt->ch_convert == '%')
		opt->str_arg[0] = '%';
	else
		opt->str_arg[0] = (char)va_arg(curr_arg, int);

}
