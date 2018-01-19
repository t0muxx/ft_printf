/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlulu <tomlulu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 14:39:10 by tomlulu           #+#    #+#             */
/*   Updated: 2018/01/19 10:48:06 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_width(t_parsed_opt *opt)
{
	char *temp;
	char sign[2];

		//printf("++++|%d|+++++ %d %s\n", opt->in_width, __LINE__, __FILE__);
		//printf("++++|%d|+++++ %d %s\n", opt->in_precision, __LINE__, __FILE__);
	if (opt->bin_flag & FLG_ZERO && opt->in_precision == -1)
	{
		if (opt->bin_flag & FLG_SHARP && (opt->ch_convert == 'x' || opt->ch_convert == 'X'))
		{
			opt->in_width -= 2;
			temp = opt->str_arg;
			opt->str_arg = ft_strsub(opt->str_arg, 2, ft_strlen(opt->str_arg));
			free(temp);
			while ((int)ft_strlen(opt->str_arg) < opt->in_width)
			{
				temp = opt->str_arg;
				opt->str_arg = ft_strjoin("0", opt->str_arg);
				free(temp);
			}
			temp = opt->str_arg;
			opt->str_arg = ft_strjoin("0x", opt->str_arg);
			free(temp);

		}
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
	//printf("++++|%d|+++++ %d %s\n", opt->in_width, __LINE__, __FILE__);
	//printf("++++|%d|+++++ %d %s\n", opt->in_precision, __LINE__, __FILE__);
	if (opt->in_width > 0)
	{
	//	printf("++++|%d|+++++ %d %s\n", (int)ft_strlen(opt->str_arg), __LINE__, __FILE__);
	//	printf("++++|%s|+++++ %d %s\n", opt->str_arg, __LINE__, __FILE__);
		if (opt->str_arg[0] == '\0' || ft_strlen(opt->str_arg) == 0)
		{
			//printf("++++|%d|+++++ %d %s\n", (int)ft_strlen(opt->str_arg), __LINE__, __FILE__);
			free(opt->str_arg);
			opt->str_arg = ft_strdup(" ");
			while ((int)ft_strlen(opt->str_arg) < opt->in_width)
			{
				temp = opt->str_arg;
				opt->str_arg = ft_strjoin(" ", opt->str_arg);
				free(temp);
			}
		}
		else
		{
			while ((int)ft_strlen(opt->str_arg) < opt->in_width)
			{
			//	printf("++++|%d|+++++ %d %s\n", (int)ft_strlen(opt->str_arg), __LINE__, __FILE__);
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
}
