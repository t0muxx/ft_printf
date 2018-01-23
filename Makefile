# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tomlulu <tomlulu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/09 15:05:31 by tomlulu           #+#    #+#              #
#    Updated: 2018/01/23 09:38:43 by tmaraval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = 	ft_printf.c \
		ft_printf_parser.c \
		ft_printf_parser_utils.c \
		ft_printf_utils.c \
		ft_printf_precision.c \
		ft_printf_str_precision.c \
		ft_printf_width.c \
		ft_printf_cwidth.c \
		ft_printf_num_flag.c \
		ft_printf_flag_utils.c \
		conv/ft_conv.c \
		conv/ft_conv_integer.c \
		conv/ft_lltoa_base.c \
		conv/ft_ulltoa_base.c \
		conv/ft_conv_char.c \
		conv/ft_conv_str.c \
		libft/ft_atoi.c \
		libft/ft_bzero.c \
		libft/ft_isalnum.c \
		libft/ft_isalpha.c \
		libft/ft_isascii.c \
		libft/ft_isdigit.c \
		libft/ft_isprint.c \
		libft/ft_itoa.c \
		libft/ft_itoa_base.c \
		libft/ft_lstadd.c \
		libft/ft_lstdel.c \
		libft/ft_lstdelone.c \
		libft/ft_lstiter.c \
		libft/ft_lstmap.c \
		libft/ft_lstnew.c \
		libft/ft_memalloc.c \
		libft/ft_memccpy.c \
		libft/ft_memchr.c \
		libft/ft_memcmp.c \
		libft/ft_memcpy.c \
		libft/ft_memdel.c \
		libft/ft_memmove.c \
		libft/ft_memset.c \
		libft/ft_putchar.c \
		libft/ft_putchar_fd.c \
		libft/ft_putendl.c \
		libft/ft_putendl_fd.c \
		libft/ft_putnbr.c \
		libft/ft_putnbr_fd.c \
		libft/ft_putstr.c \
		libft/ft_putstr_color.c \
		libft/ft_putstr_fd.c \
		libft/ft_str_is_lowercase.c \
		libft/ft_str_is_numeric.c \
		libft/ft_strcat.c \
		libft/ft_strchr.c \
		libft/ft_strclr.c \
		libft/ft_strcmp.c \
		libft/ft_strcpy.c \
		libft/ft_strdel.c \
		libft/ft_strdup.c \
		libft/ft_strequ.c \
		libft/ft_striter.c \
		libft/ft_striteri.c \
		libft/ft_strjoin.c \
		libft/ft_strlcat.c \
		libft/ft_strlen.c \
		libft/ft_strlowcase.c \
		libft/ft_strmap.c \
		libft/ft_strmapi.c \
		libft/ft_strncat.c \
		libft/ft_strncmp.c \
		libft/ft_strncpy.c \
		libft/ft_strnequ.c \
		libft/ft_strnew.c \
		libft/ft_strnstr.c \
		libft/ft_strrchr.c \
		libft/ft_strrev.c \
		libft/ft_strrpl.c \
		libft/ft_strsplit.c \
		libft/ft_strstr.c \
		libft/ft_strsub.c \
		libft/ft_strtrim.c \
		libft/ft_strupcase.c \
		libft/ft_tolower.c \
		libft/ft_toupper.c \
		libft/ft_wcstrlen.c \
		libft/ft_wcstrsub.c \
		libft/ft_wcstrjoin.c


OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

./%.o: %.c
	gcc -g -c $< -o $@

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
