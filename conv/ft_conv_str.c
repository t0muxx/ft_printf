/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:59:46 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/22 17:40:27 by tomlulu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"



void	ft_conv_str(t_parsed_opt *opt, va_list curr_arg)
{
	int i;
	char *wstr;
	char *temp;
	wchar_t ch;

	i = 0;
	opt->str_arg = ft_memalloc(5);
	ft_bzero(opt->str_arg, 5);
	temp = opt->str_arg;
	if (opt->bin_lenmod & LENMOD_L || opt->ch_convert == 'S')
	{
		wstr = ft_memalloc(5);
		opt->wstr_arg = (wchar_t *)va_arg(curr_arg, wchar_t *);
		while (opt->wstr_arg[i])
		{
			temp = opt->str_arg;
			ft_bzero(wstr, 5);
			ch = (wchar_t)opt->wstr_arg[i];
			if (ch <= 0x7f)
			{
				wstr[0] = ch;
			}
			else if (ch <= 0x7FF)
			{
				wstr[0] = 0xC0 | ((ch >> 6) & 0x1F);
				wstr[1] = 0x80 | (ch & 0x3F);
			}
			else if (ch <= 0xFFFF)
			{
				wstr[0] = 0xE0 |  ((ch >> 12) & 0x0F);
				wstr[1] = 0x80 |  ((ch >> 6) & 0x3F);
				wstr[2] = 0x80 |  (ch & 0x3F);
			}
			else if (ch <= 0x10FFFF)
			{
				wstr[0] = 0xF0 | ((ch >> 18) & 0x07);
				wstr[1] = 0x80 |  ((ch >> 12) & 0x3F);
				wstr[2] = 0x80 |  ((ch >> 6) & 0x3F);
				wstr[3] = 0x80 |  (ch & 0x3F);
			}
			else
			{
				;
			}
			//write(1, wstr, ft_strlen(wstr));
			opt->str_arg = ft_strjoin(opt->str_arg, wstr);
			free(temp);
			i++;
		}
		free(wstr);
	}
	else
	{
		opt->str_arg = (char *)va_arg(curr_arg, char *);
		if (opt->str_arg != NULL)
			opt->str_arg = ft_strdup(opt->str_arg);
		else
			opt->str_arg = ft_strdup("(null)");
	}
}
