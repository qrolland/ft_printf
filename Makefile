# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qrolland <qrolland@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 16:02:28 by qrolland          #+#    #+#              #
#    Updated: 2022/06/30 16:03:20 by qrolland         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CFLAGS		= -Wall -Wextra -Werror -I./includes -c
LIBFT		= ./libft/libft.a
FILES		= srcs/ft_printf.c \
			  srcs/ft_conversion_char.c \
			  srcs/ft_conversion_string.c \
			  srcs/ft_read_flags.c \
			  srcs/ft_conversion_ptr.c \
			  srcs/ft_conversion_int.c \
			  srcs/ft_conversion_unsigned.c \
			  srcs/ft_conversion_hex.c \
			  srcs/ft_conversion_percent.c
			  	
OBJ			= $(FILES:%.c=%.o)

all: $(NAME) 

$(LIBFT):
	@make all -C libft
	mv $(LIBFT) $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o : %.c
	gcc $(CFLAGS) -o $@ -c $< 

clean:
	rm -f $(OBJ)
	@make clean -C libft

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus
