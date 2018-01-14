/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlulu <tomlulu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 14:39:10 by tomlulu           #+#    #+#             */
/*   Updated: 2018/01/14 15:28:04 by tomlulu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_width(t_parsed_opt *opt)
{
	char *temp;

	while (ft_strlen(opt->str_arg) < opt->in_width)
	{
		temp = opt->str_arg;
		if (opt->bin_flag & FLG_MINUS)
			opt->str_arg = ft_strjoin(opt->str_arg, " ");
		else
			opt->str_arg = ft_strjoin(" ", opt->str_arg);
		free(temp);
	}
}
