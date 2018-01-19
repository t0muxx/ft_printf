/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlulu <tomlulu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 10:08:03 by tomlulu           #+#    #+#             */
/*   Updated: 2018/01/18 15:04:04 by tomlulu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_precision(t_parsed_opt *opt)
{
	char	*temp;
	char	sign[2];

	//printf("++++|%s|+++++ %d %s\n", opt->in_precision, __LINE__, __FILE__);
	//printf("++++|%s|+++++ %d %s\n", opt->str_arg, __LINE__, __FILE__);
	if (ft_strchr("oOxXdupiDU" ,opt->ch_convert) && opt->in_precision > 0)
	{
		if (opt->str_arg[0] == '-' || opt->str_arg[0] == '+')
		{
			sign[0] = opt->str_arg[0];
			temp = opt->str_arg;
			opt->str_arg = ft_strsub(opt->str_arg, 1, ft_strlen(opt->str_arg));
			free(temp);
			while (ft_strlen(opt->str_arg) < (size_t)opt->in_precision)
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
			while ((int)ft_strlen(opt->str_arg) < opt->in_precision)
			{
				temp = opt->str_arg;
				opt->str_arg = ft_strjoin("0", opt->str_arg);
				free(temp);
			}
		}
	}
//	printf("++++|%s|+++++ %d %s\n", opt->str_arg, __LINE__, __FILE__);
	/* On affiche pas le 0 dans ces deux cas */
	if (opt->in_precision == 0 && !(opt->bin_flag & FLG_SHARP) && ft_strcmp("0", opt->str_arg) == 0)
	{
		opt->str_arg[0] = '\0';
	}
	else if ((opt->bin_flag & FLG_SHARP) && !(ft_strchr("oO", opt->ch_convert))
	&& opt->in_precision == 0 && ft_strcmp("0", opt->str_arg) == 0 )
		opt->str_arg[0] = '\0';
//	printf("++++|%s|+++++ %d %s\n", opt->str_arg, __LINE__, __FILE__);
}
