/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlulu <tomlulu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:31:40 by tomlulu           #+#    #+#             */
/*   Updated: 2018/01/09 20:08:55 by tomlulu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_print_opt(t_parsed_opt opt)
{
	printf("arnbr = |%d|\n", opt.in_argnbr);
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
}
