# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jthomas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 15:21:01 by jthomas           #+#    #+#              #
#    Updated: 2022/12/06 23:43:19 by jthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(OS),Windows_NT)
	DIRSEP	= \\
	RM		= del
else
	DIRSEP	= /
	RM		= rm -f
endif

NAME		= libftprintf.a

SRCS		= src${DIRSEP}ft_printf.c src${DIRSEP}ft_isflag.c src${DIRSEP}ft_printflag.c

OBJS		= ${SRCS:.c=.o}

CC			= gcc

CFLAGS		= -c -Wall -Wextra -Werror

LIBFT 		= ar -crs ${NAME} ${OBJS}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${SRCS}
	${LIBFT}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean:
	${RM} ${OBJS}
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
