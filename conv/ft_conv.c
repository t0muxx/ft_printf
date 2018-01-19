/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 10:29:20 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/19 11:39:36 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_conv(t_parsed_opt *opt, va_list curr_arg)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	if (ft_strchr("oOxXdDuUpi", opt->ch_convert))
	{
		ft_conv_integer(opt, curr_arg);
		//printf("\n++++|%s|+++++ %d %s\n", opt->str_arg, __LINE__, __FILE__);
		ft_printf_num_manage_flag(opt);
		//printf("\n++++|%s|+++++ %d %s\n", opt->str_arg, __LINE__, __FILE__);
		ft_printf_precision(opt);
		//printf("\n++++|%s|+++++ %d %s\n", opt->str_arg, __LINE__, __FILE__);
		ft_printf_width(opt);
		//printf("\n++++|%s|+++++ %d %s\n", opt->str_arg, __LINE__, __FILE__);
		if (opt->ch_convert == 'X')
			ft_strupcase(opt->str_arg);
	}
	if (ft_strchr("cC%", opt->ch_convert))
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
		ret = (int)ft_wcstrlen(opt->wstr_arg);
		while (opt->wstr_arg[i])
		{
			write(1, &opt->wstr_arg[i], 1);
			i++;
		}
		free(opt->wstr_arg);
	}
	else
	{
		if (opt->str_arg != NULL && opt->ch_convert != 'S')
		{
			if ((opt->ch_convert == 'c' || opt->ch_convert == 'C'))
			{
				if (opt->ch_ch == 0)
				{
					write(1, opt->str_arg, ft_strlen(opt->str_arg) + 1);
					return (ft_strlen(opt->str_arg) + 1);
				}
				else
				{
					write(1, opt->str_arg, ft_strlen(opt->str_arg));
					return (ft_strlen(opt->str_arg));
				}
			}
			ret = (int)ft_strlen(opt->str_arg);
			write(1, opt->str_arg, ft_strlen(opt->str_arg));
			free(opt->str_arg);
		}
	}
	return (ret);
}
