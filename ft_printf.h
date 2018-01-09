/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 13:34:47 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/09 21:52:55 by tomlulu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"
#include <limits.h>

# define TRUE 1
# define FALSE 0

# define AVAILABLE_FLAG "#0- +"

# define FLG_SHARP 1
# define FLG_ZERO 2
# define FLG_MINUS 4
# define FLG_SP 8
# define FLG_PLUS 16

typedef	struct 	s_parsed_opt
{
	int				bin_flag;
	int				in_width;
	int				in_precision;
	char			pch_lengthmod[3];
	char			ch_convert;
	int				in_argnbr;

}				t_parsed_opt;

void	ft_parser_init_t_parsed_opt(t_parsed_opt *opt);
int		ft_parser(t_parsed_opt *opt, char **format);
int		ft_parser_managepercent(char **format);
int		ft_parser_read_int_upd_str(char **format);
void	ft_parser_manage_argnbr(char **format, char **begin, t_parsed_opt *opt);
void	ft_parser_manage_flag(char **format, t_parsed_opt *opt);

void	ft_printf_print_opt(t_parsed_opt opt);
#endif
