# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juho <juho@student.42kl.edu.my>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/01 13:15:49 by juho              #+#    #+#              #
#    Updated: 2026/09/01 13:44:59 by juho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFTDIR = libft

SRC = ft_printf.c \
	ft_printf_utils.c 

OBJS = ${SRC:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

LIBFT = $(LIBFTDIR)/libft.a

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -I. -I${LIBFTDIR} -c $< -o $@

${LIBFT}:
	${MAKE} -C ${LIBFTDIR}

${NAME}: ${LIBFT} ${OBJS} 
	cp ${LIBFT} ${NAME}
	ar rcs ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	${RM} ${NAME}
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re