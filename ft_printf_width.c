/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlulu <tomlulu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 14:39:10 by tomlulu           #+#    #+#             */
/*   Updated: 2018/01/18 15:08:42 by tomlulu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_width(t_parsed_opt *opt)
{
	char *temp;
	char sign[2];

	if (opt->bin_flag & FLG_ZERO && opt->in_precision == -1)
	{
		if (opt->str_arg[0] == '+' || opt->str_arg[0] == '-')
		{
			sign[0] = opt->str_arg[0];
			temp = opt->str_arg;
			opt->str_arg = ft_strsub(opt->str_arg, 1, ft_strlen(opt->str_arg));
			free(temp);
			while ((int)ft_strlen(opt->str_arg) + 1 < opt->in_width)
			{
				temp = opt->str_arg;
				opt->str_arg = ft_strjoin("0", opt->str_arg);
				free(temp);
			}
			temp = opt->str_arg;
			sign[1] = '\0';
			opt->str_arg = ft_strjoin(sign, opt->str_arg);
			free(temp);
		}
		else
		{
			while ((int)ft_strlen(opt->str_arg) < opt->in_width)
			{
				temp = opt->str_arg;
				opt->str_arg = ft_strjoin("0", opt->str_arg);
				free(temp);
			}
		}
	}
	if (opt->in_precision != -1)
	{
		while ((int)ft_strlen(opt->str_arg) < opt->in_width)
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
}
