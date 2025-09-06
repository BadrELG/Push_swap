# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: badr <badr@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/06 09:55:00 by badr              #+#    #+#              #
#    Updated: 2025/08/09 23:29:29 by badr             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = main.c \
       parsing.c \
       Commands/push.c \
       Commands/rotate.c \
       Commands/rev_rotate.c \
       Commands/swap.c \
       sort/radix_sort.c \
       sort/small_sort.c \
       sort/sort_utils.c \
       sort/move_utils.c

OBJS = ${SRCS:.c=.o}

LIBFT = libft
LIBFT_A = ${LIBFT}/libft.a

all: ${NAME}

${NAME}: ${OBJS}
	make -C ${LIBFT}
	${CC} ${CFLAGS} ${OBJS} ${LIBFT_A} -o ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${OBJS}
	make clean -C ${LIBFT}

fclean: clean
	${RM} ${NAME}
	make fclean -C ${LIBFT}

re: fclean all

.PHONY: all clean fclean re
