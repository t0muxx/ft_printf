/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_test.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:25:45 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/15 10:10:01 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define AVAILABLE_FLAG "#0- +"
# define AVAILABLE_LENMOD "hljz"
# define AVAILABLE_CONV "sSpcoOxXdiu"

#include <stdlib.h>
#include <time.h>// pour rand
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	test_fuzz_opt();
void	test_big_width_prec_argnbr();
void	test_conv();
void	test_convert();
void	test_convert_printf();
void	test_width_printf();
void	test_width();
void	test_width_printf_plusminus();
void	test_width_plusminus();
void	test_ptr();
void	test_width_printf_plusminussharp();
void	test_width_plusminussharp();
