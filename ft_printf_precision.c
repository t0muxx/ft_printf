/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlulu <tomlulu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 10:08:03 by tomlulu           #+#    #+#             */
/*   Updated: 2018/01/14 12:33:51 by tomlulu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_precision(t_parsed_opt *opt)
{
	char *temp;

	if (ft_strchr("oOxXdupi" ,opt->ch_convert) && opt->in_precision > 0)
	{
		if (opt->str_arg[0] == '-')
		{
			temp = opt->str_arg;
			opt->str_arg = ft_strsub(opt->str_arg, 1, ft_strlen(opt->str_arg));
			write(1, "-", 1);
			free(temp);
		}
		while (ft_strlen(opt->str_arg) < opt->in_precision)
		{
			temp = opt->str_arg;
			opt->str_arg = ft_strjoin("0", opt->str_arg);
			free(temp);
		}
	}
	if (opt->in_precision == -1 && ft_strcmp(opt->str_arg, "0") == 0)
	{
		free(opt->str_arg);
		opt->str_arg = NULL;
	}
}
