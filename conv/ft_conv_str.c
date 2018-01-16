/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:59:46 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/16 17:06:20 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_conv_str(t_parsed_opt *opt, va_list curr_arg)
{
	if (opt->bin_lenmod & LENMOD_L || opt->ch_convert == 'S')
		opt->wstr_arg = va_arg(curr_arg, wchar_t *);
	else
		opt->str_arg = ft_strdup((char *)va_arg(curr_arg, char *));
}
