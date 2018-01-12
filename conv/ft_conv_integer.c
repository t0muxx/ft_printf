/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_integer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 10:22:35 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/12 12:50:28 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_conv_int_arg_wlenmod(t_parsed_opt *opt, va_list curr_arg)
{

	if (opt->bin_lenmod & LENMOD_H)
	{
		if (ft_strchr("di", opt->ch_convert))
			opt->str_arg = ft_lltoa_base((short int)va_arg(curr_arg, int), opt->in_base);
		else
			opt->str_arg = ft_ulltoa_base((unsigned long long)va_arg(curr_arg, int), opt->in_base);
	}
	if (opt->bin_lenmod & LENMOD_HH)
	{
		if (ft_strchr("di", opt->ch_convert))
			opt->str_arg = ft_lltoa_base((char)va_arg(curr_arg, int), opt->in_base);
		else
			opt->str_arg = ft_ulltoa_base((unsigned char)va_arg(curr_arg, int), opt->in_base);
	}
	if (opt->bin_lenmod & LENMOD_L)
	{
		if (ft_strchr("di", opt->ch_convert))
			opt->str_arg = ft_lltoa_base((long int)va_arg(curr_arg, long), opt->in_base);
		else
			opt->str_arg = ft_ulltoa_base((unsigned long int)va_arg(curr_arg, int), opt->in_base);
	}
	if (opt->bin_lenmod & LENMOD_LL)
	{
		if (ft_strchr("di", opt->ch_convert))
			opt->str_arg = ft_lltoa_base((long long)va_arg(curr_arg, long long), opt->in_base);
		else
			opt->str_arg = ft_ulltoa_base((unsigned long long)va_arg(curr_arg, unsigned long long), opt->in_base);
	}
	if (opt->bin_lenmod & LENMOD_J)
	{
		if (ft_strchr("di", opt->ch_convert))
			opt->str_arg = ft_lltoa_base((intmax_t)va_arg(curr_arg, intmax_t), opt->in_base);
		else
			opt->str_arg = ft_ulltoa_base((uintmax_t)va_arg(curr_arg, uintmax_t), opt->in_base);
	}
	if (opt->bin_lenmod & LENMOD_Z)
	{
		if (ft_strchr("di", opt->ch_convert))
			opt->str_arg = ft_lltoa_base((size_t)va_arg(curr_arg, size_t), opt->in_base);
		else
			opt->str_arg = ft_ulltoa_base((size_t)va_arg(curr_arg, size_t), opt->in_base);
	}
	return (0);
}

int		ft_conv_int_arg(t_parsed_opt *opt, va_list curr_arg)
{
	if (opt->bin_lenmod)
		ft_conv_int_arg_wlenmod(opt, curr_arg);
	else
	{
		if (opt->ch_convert == 'd' || opt->ch_convert == 'i')
			opt->str_arg = ft_lltoa_base((long long)va_arg(curr_arg, int), 10);
		if (opt->ch_convert == 'u')
			opt->str_arg = ft_ulltoa_base((unsigned long long)va_arg(curr_arg, unsigned int), 10);
		if (opt->ch_convert == 'x' || opt->ch_convert == 'X')
			opt->str_arg = ft_ulltoa_base((unsigned long long)va_arg(curr_arg, unsigned int), 16);
		if (opt->ch_convert == 'o' || opt->ch_convert == 'O')
			opt->str_arg = ft_ulltoa_base((unsigned long long)va_arg(curr_arg, unsigned int), 8);
		if (opt->ch_convert == 'p')
			opt->str_arg = ft_lltoa_base((long long)va_arg(curr_arg, void *), 16);
	}
	return (0);
}

void	ft_conv_int_manage_flag(t_parsed_opt *opt, char **temp, char *begin)
{
	if (opt->bin_flag & FLG_SHARP)
	{
		if (opt->ch_convert == 'o' || opt->ch_convert == 'O')
		{
			*temp = ft_memalloc(2);
			begin = *temp;
			ft_bzero(*temp, 2);
			ft_strcpy(*temp, "0");
			*temp  = *(temp + 1);
			printf("\n++++|%s|+++++ %d %s\n", begin, __LINE__, __FILE__);
		}
		if (opt->ch_convert == 'x' || opt->ch_convert == 'X')
		{
			*temp = ft_memalloc(3);
			begin = *temp;
			ft_bzero(*temp, 3);
			ft_strcpy(*temp, "0x");
			*temp  = *(temp + 2);
			printf("\n++++|%s|+++++ %d %s\n", begin, __LINE__, __FILE__);
		}
	}
}

int		ft_conv_integer(t_parsed_opt *opt, va_list curr_arg)
{
	char *temp;
	char *begin;

	temp = NULL;
	begin = NULL;
	ft_conv_int_manage_flag(opt, &temp, begin);
	ft_conv_int_arg(opt, curr_arg);
	return (0);
}
