/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_test.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:25:45 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/11 10:09:48 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define AVAILABLE_FLAG "#0- +"
# define AVAILABLE_LENMOD "hljz"
# define AVAILABLE_CONV "sSpcoOxXdiu"
#include <stdlib.h>
#include <time.h>// pour rand
#include <unistd.h>
void	test_fuzz_opt(int lopptime);
void	test_big_width_prec_argnbr();
void	test_conv();
