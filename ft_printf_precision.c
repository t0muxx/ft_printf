/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlulu <tomlulu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 10:08:03 by tomlulu           #+#    #+#             */
/*   Updated: 2018/01/16 09:20:10 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_precision(t_parsed_opt *opt)
{
	char	*temp;
	int		isneg;
	char	sign;

	isneg = FALSE;
	//printf("++++|%d|+++++ %d %s\n", opt->in_precision, __LINE__, __FILE__);
	//printf("++++|%s|+++++ %d %s\n", opt->str_arg, __LINE__, __FILE__);
	if (ft_strchr("oOxXdupi" ,opt->ch_convert) && opt->in_precision > 0)
	{
		if (opt->str_arg[0] == '-' || opt->str_arg[0] == '+')
		{
			sign = opt->str_arg[0];
			temp = opt->str_arg;
			opt->str_arg = ft_strsub(opt->str_arg, 1, ft_strlen(opt->str_arg));
			free(temp);
			while (ft_strlen(opt->str_arg) < opt->in_precision)
			{
				temp = opt->str_arg;
				opt->str_arg = ft_strjoin("0", opt->str_arg);
				free(temp);
			}
			temp = opt->str_arg;
			opt->str_arg = ft_strjoin(&sign, opt->str_arg);
			free(temp);
		}
		else
		{
			while (ft_strlen(opt->str_arg) < opt->in_precision)
			{
				temp = opt->str_arg;
				opt->str_arg = ft_strjoin("0", opt->str_arg);
				free(temp);
			}
		}
	}
	/* On affiche pas le 0 dans ces deux cas */
	if (opt->bin_flag != 0 || (opt->in_precision == 0))
	{
		if (opt->in_precision <= 0 && ft_strcmp(opt->str_arg, "0") == 0
		&& ft_strchr("xXidiu", opt->ch_convert))
		{
			ft_strcpy(opt->str_arg, "\0");
		}
		if (opt->in_precision <= 0 && ft_strcmp(opt->str_arg, "0") == 0
		&& ft_strchr("oO", opt->ch_convert) && ((opt->bin_flag & FLG_SHARP) == 0))
			ft_strcpy(opt->str_arg, "\0");
	}
}
