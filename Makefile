# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juho <juho@student.42kl.edu.my>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/01 13:15:49 by juho              #+#    #+#              #
#    Updated: 2026/09/03 17:17:26 by juho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c \
	ft_helpers.c

OBJS = ${SRC:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -I. -c $< -o $@


${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re