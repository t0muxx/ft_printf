/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlulu <tomlulu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 16:27:58 by tomlulu           #+#    #+#             */
/*   Updated: 2018/01/18 11:48:48 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parser_managepercent(char **format)
{
	char *begin;

	begin = *format;
	begin++;
	//printf("\n++++|%c|+++++ %d %s\n", *begin, __LINE__, __FILE__);
	while (*begin == ' ')
	{
		begin++;
	}
	if (*begin == '%')
	{
		*format = begin;
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

int		ft_parser_read_int_upd_str(char **format)
{
	int ret;
	int isnega;

	isnega = FALSE;
	if (**format == '-')
	{
		(*format)++;
		ret = **format - '0';
		isnega = TRUE;
	}
	else
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
	if (isnega == TRUE)
		ret *= -1;
	return (ret);
}

void	ft_parser_manage_argnbr(char **format, char *begin, t_parsed_opt *opt)
{
	int nbr;

	nbr = 0;
//	printf("\n++++|%c|+++++ %d %s\n", **format, __LINE__, __FILE__);
	if (ft_isdigit(**format))
	{
		nbr = ft_parser_read_int_upd_str(format);
//		printf("\n++++|%c|+++++ %d %s\n", **format, __LINE__, __FILE__);
		if (**format == '$')
		{
//			printf("\n++++|%c|+++++ %d %s\n", **format, __LINE__, __FILE__);
			opt->in_argnbr = nbr;
			(*format)++;
//			printf("\n++++|%c|+++++ %d %s\n", **format, __LINE__, __FILE__);
		}
		else
			*format = begin;
//		printf("\n++++|%c|+++++ %d %s\n", *begin, __LINE__, __FILE__);
//		printf("\n++++|%c|+++++ %d %s\n", **format, __LINE__, __FILE__);
	}
}

void	ft_parser_manage_flag(char **format, t_parsed_opt *opt)
{
	while (ft_strchr(AVAILABLE_FLAG, **format) && **format)
	{
		opt->bin_flag |= **format == '#' ? FLG_SHARP : 0;
		opt->bin_flag |= **format == '0' ? FLG_ZERO : 0;
		opt->bin_flag |= **format == '-' ? FLG_MINUS : 0;
		opt->bin_flag |= **format == ' ' ? FLG_SP : 0;
		opt->bin_flag |= **format == '+' ? FLG_PLUS : 0;
		(*format)++;
	}
	if ((opt->bin_flag & FLG_SP) && (opt->bin_flag & FLG_PLUS))
		opt->bin_flag &= ~(1 << 3);
	if ((opt->bin_flag & FLG_ZERO) && (opt->bin_flag & FLG_MINUS))
		opt->bin_flag &= ~(1u << 1);
}

void	ft_parser_manage_width(char **format, t_parsed_opt *opt)
{
	int nbr;

	nbr = 0;
	// Gestion du flag * et & //////////////////////////////
	if (**format == '*')
	{
		(*format)++;
		if (ft_isdigit(**format))
		{
			nbr = ft_parser_read_int_upd_str(format);
			//printf("\n++++|%d|+++++ %d %s\n", nbr, __LINE__, __FILE__);
			if (**format == '$')
			{
				(*format)++;
				while (nbr > 0)
				{
				//	printf("\n++++|%d|+++++ %d %s\n", nbr, __LINE__, __FILE__);
					opt->in_width = 0;
					nbr--;
				}
			}
		}
		else
			opt->in_width = 0;
	}
	else
	{
		// ///////////////// //////////////////////////////
		if (ft_isdigit(**format))
		{
			nbr = ft_parser_read_int_upd_str(format);
			opt->in_width = nbr;
		}
	}
}
