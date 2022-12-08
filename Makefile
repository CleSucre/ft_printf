# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jthomas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 15:21:01 by jthomas           #+#    #+#              #
#    Updated: 2022/12/08 02:42:19 by jthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(OS), Windows_NT)
	DIRSEP	= \\
	RM		= del
else
	DIRSEP	= /
	RM		= rm -f
endif

NAME		= libftprintf.a

SRCS		= src${DIRSEP}ft_printf.c src${DIRSEP}ft_isflag.c src${DIRSEP}ft_printflag.c \
			  src${DIRSEP}ft_printchar.c src${DIRSEP}ft_printstr.c src${DIRSEP}ft_printnbr.c \
			  src${DIRSEP}ft_printhex.c src${DIRSEP}ft_printunsigned.c src${DIRSEP}ft_printptr.c

OBJS		= ${SRCS:.c=.o}

CC			= gcc

HEAD		= includes

CFLAGS		= -c -Wall -Wextra -Werror -I ${HEAD}

LIBFT 		= ar -crs ${NAME} ${OBJS} libft/src/*.o

${NAME}: libft.a ${OBJS}
	${LIBFT}

libft.a:
	${MAKE} -C .${DIRSEP}libft all

all: ${NAME}

clean:
	${RM} ${OBJS}
	${MAKE} -C .${DIRSEP}libft clean

fclean:
	${RM} ${OBJS}
	${RM} ${NAME}
	${MAKE} -C .${DIRSEP}libft fclean

re: fclean all

.PHONY: all clean fclean re libft.a
