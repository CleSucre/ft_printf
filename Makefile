# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jthomas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 15:21:01 by jthomas           #+#    #+#              #
#    Updated: 2022/11/11 05:28:01 by jthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

IS_WIN	:=

ifeq ($(OS),Windows_NT)
	IS_WIN = 1
else
	IS_WIN = 0
endif

ifeq (${IS_WIN}, 1)
	DIRSEP	= \\
	CP		= copy
	RM		= del
else
	DIRSEP	= /
	CP		= cp
	RM		= rm -f
endif

NAME		= libftprintf.a

SRCS		= src${DIRSEP}ft_printf.c src${DIRSEP}ft_isflag.c src${DIRSEP}ft_printflag.c

OBJS		= ${SRCS:.c=.o}

CC			= gcc

CFLAGS		= -c -Wall -Wextra -Werror -I ./includes -I ./libft

LIBFT 		= ar -crs ${NAME} ${OBJS}

${NAME}: ${OBJS}
	${MAKE} all -C ./libft
	${CP} libft${DIRSEP}libft.a ${NAME}
	${CC} ${CFLAGS} ${SRCS}
	${LIBFT}

all: ${NAME}

clean:
	${MAKE} clean -C ./libft
	${RM} ${OBJS}

fclean:
	${MAKE} fclean -C ./libft
	${RM} ${OBJS}
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
