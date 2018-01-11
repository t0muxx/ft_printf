/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 10:29:20 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/11 15:12:04 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_conv(t_parsed_opt *opt, va_list curr_arg)
{
	int ret;

	ret = 0;
	if (ft_strchr("oOxXdup", opt->ch_convert))
		ret = ft_conv_integer(opt, curr_arg);

	return (ret);
}
