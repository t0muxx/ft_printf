/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 07:52:49 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/15 17:23:08 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_strarg_isnega(t_parsed_opt *opt)
{
	int i;

	i = 0;
	while (opt->str_arg[i])
	{
		if (ft_strchr("123456789abcdef", opt->str_arg[i]) != NULL)
			return (1);
		i++;
	}
	return (0);
}

void	ft_printf_manage_flag(t_parsed_opt *opt)
{
	char *temp;

	if (opt->bin_flag & FLG_SHARP || opt->ch_convert == 'p')
	{
		if (opt->ch_convert == 'o' || opt->ch_convert == 'O')
		{
			temp = opt->str_arg;
			if (ft_printf_strarg_isnega(opt) != 0)
			{
				opt->str_arg = ft_strjoin("0", opt->str_arg);
				free(temp);
			}
		}
		if (opt->ch_convert == 'x' || opt->ch_convert == 'X' || opt->ch_convert == 'p')
		{
			ft_printf_precision(opt);
			temp = opt->str_arg;
			if (ft_printf_strarg_isnega(opt) != 0)
			{
				opt->str_arg = ft_strjoin("0x", opt->str_arg);
				free(temp);
			}
		}
	}
	if (opt->bin_flag & FLG_SP)
	{
		if (opt->str_arg[0] != '-')
		{
			temp = opt->str_arg;
			opt->str_arg = ft_strjoin(" ", opt->str_arg);
			free(temp);
		}
	}
	if (opt->bin_flag & FLG_PLUS)
	{
		if (opt->str_arg[0] != '-')
		{
			temp = opt->str_arg;
			opt->str_arg = ft_strjoin("+", opt->str_arg);
			free(temp);
		}
	}
}
