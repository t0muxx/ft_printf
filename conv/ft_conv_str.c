/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:59:46 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/17 10:11:27 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_conv_str(t_parsed_opt *opt, va_list curr_arg)
{
	if (opt->bin_lenmod & LENMOD_L || opt->ch_convert == 'S')
	{
		opt->wstr_arg = (wchar_t *)va_arg(curr_arg, wchar_t *);
		opt->wstr_arg = ft_wcstrsub(opt->wstr_arg, 0, ft_wcstrlen(opt->wstr_arg));
	}
	else
	{
		opt->str_arg = (char *)va_arg(curr_arg, char *);
		if (opt->str_arg != NULL)
			opt->str_arg = ft_strdup(opt->str_arg);
		else
			opt->str_arg = ft_strdup("(null)");
	}
}
