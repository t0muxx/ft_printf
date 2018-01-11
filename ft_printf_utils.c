/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlulu <tomlulu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:31:40 by tomlulu           #+#    #+#             */
/*   Updated: 2018/01/11 15:12:21 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_print_opt(t_parsed_opt opt)
{
	printf("argnbr : |%d|\n", opt.in_argnbr);
	printf("in_width : |%d|\n", opt.in_width);
	printf("in_precision : |%d|\n", opt.in_precision);
	printf("ch_convert : |%c|\n", opt.ch_convert);
	printf("opt->str_arg : |%s|\n", opt.str_arg);
	printf("opt->in_base : |%d|\n", opt.in_base);
	if (opt.bin_flag & FLG_SHARP)
	{
		printf("flag # trouve\n");
	}
	if (opt.bin_flag & FLG_ZERO)
	{
		printf("flag 0 trouve\n");
	}
	if (opt.bin_flag & FLG_MINUS)
	{
		printf("flag - trouve\n");
	}
	if (opt.bin_flag & FLG_SP)
	{
		printf("flag space trouve\n");
	}
	if (opt.bin_flag & FLG_PLUS)
	{
		printf("flag + trouve\n");
	}
	if (opt.bin_lenmod & LENMOD_H)
	{
		printf("len mod H\n");
	}
	if (opt.bin_lenmod & LENMOD_HH)
	{
		printf("len mod HH\n");
	}
	if (opt.bin_lenmod & LENMOD_L)
	{
		printf("len mod L\n");
	}
	if (opt.bin_lenmod & LENMOD_LL)
	{
		printf("len mod LL\n");
	}
	if (opt.bin_lenmod & LENMOD_J)
	{
		printf("len mod J\n");
	}
	if (opt.bin_lenmod & LENMOD_Z)
	{
		printf("len mod Z\n");
	}
}
