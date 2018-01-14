# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tomlulu <tomlulu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/09 15:05:31 by tomlulu           #+#    #+#              #
#    Updated: 2018/01/14 10:40:08 by tomlulu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = 	ft_printf.c \
		ft_printf_parser.c \
		ft_printf_parser_utils.c \
		ft_printf_utils.c \
		ft_printf_precision.c \
		conv/ft_conv.c \
		conv/ft_conv_integer.c \
		conv/ft_lltoa_base.c \
		conv/ft_ulltoa_base.c \
		libft/libft.a

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
#	(cd libft ; make; make clean)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

./%.o: %.c
	gcc -c $< -L libft/ -lft -o $@

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
