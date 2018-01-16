/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cwidth.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:11:26 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/16 15:23:58 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_cwidth(t_parsed_opt *opt)
{
	char *temp;

	//printf("\n++++|%d|+++++ %d %s\n", opt->in_width, __LINE__, __FILE__);
	while (ft_strlen(opt->str_arg) < (size_t)opt->in_width)
	{
		temp = opt->str_arg;
		if (opt->bin_flag & FLG_ZERO)
			opt->str_arg = ft_strjoin("0", opt->str_arg);
		else if (opt->bin_flag & FLG_MINUS)
			opt->str_arg = ft_strjoin(opt->str_arg, " ");
		else
			opt->str_arg = ft_strjoin(" ", opt->str_arg);
		free(temp);
	}
}
