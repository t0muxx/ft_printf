/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlulu <tomlulu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 16:27:58 by tomlulu           #+#    #+#             */
/*   Updated: 2018/01/09 20:08:54 by tomlulu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parser_managepercent(char **format)
{
	char *begin;

	begin = *format;
	begin++;
	if (*begin == '%')
	{
		(*format)++;
		(*format)++;
		ft_putchar('%');
		return (1);
	}
	return (0);
}

int		ft_parser_read_int_upd_str(char **format)
{
	int ret;

	ret = **format - '0';
	(*format)++;
	while (ft_isdigit(**format))
	{
		if (ret > INT_MAX)
			ret = -1;
		else
		{
			ret *= 10;
			ret += **format - '0';
		}
		(*format)++;
	}
	return (ret);
}
