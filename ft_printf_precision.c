/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlulu <tomlulu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 10:08:03 by tomlulu           #+#    #+#             */
/*   Updated: 2018/01/15 17:10:19 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_precision(t_parsed_opt *opt)
{
	char	*temp;
	int		isneg;

	isneg = FALSE;
	if (ft_strchr("oOxXdupi" ,opt->ch_convert) && opt->in_precision > 0)
	{
		if (opt->str_arg[0] == '-')
		{
			temp = opt->str_arg;
			opt->str_arg = ft_strsub(opt->str_arg, 1, ft_strlen(opt->str_arg));
			isneg = TRUE;
			free(temp);
		}
		while (ft_strlen(opt->str_arg) < opt->in_precision)
		{
			temp = opt->str_arg;
			opt->str_arg = ft_strjoin("0", opt->str_arg);
			free(temp);
		}
		if (isneg == TRUE)
		{
			temp = opt->str_arg;
			opt->str_arg = ft_strjoin("-", opt->str_arg);
			free(temp);
		}
	}
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
