# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhenriqu <bhenriqu@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/25 21:11:36 by bhenriqu          #+#    #+#              #
#    Updated: 2024/10/25 21:18:05 by bhenriqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_printf_char.c ft_printf_hexa.c ft_printf_num.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		@ar rcs $(NAME) $(OBJS)
		@echo "ft_printf compiled successfully"

%.o: %.c
		@$(CC) $(FLAGS) -c $< -o $@

clean: 
		@rm -f $(OBJS)
		@echo "Files object deleted"

fclean: clean
		@rm -f $(NAME)
		@echo "ft_printf deleted"

re: fclean all

.PHONY: all clean fclean re