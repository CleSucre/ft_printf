# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julthoma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 17:07:47 by julthoma          #+#    #+#              #
#    Updated: 2023/11/02 17:07:47 by julthoma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(OS), Windows_NT)
	DIRSEP	= \\
	CP		= copy
	RM		= del -f
else
	DIRSEP	= /
	CP		= cp
	RM		= rm -f
endif

NAME		= libftprintf.a

NAME_UNIT	= unit_test

SRCS		= ft_printf.c \
				print${DIRSEP}ft_putchar_fd.c \
				print${DIRSEP}ft_putstr_fd.c \
				print${DIRSEP}ft_putpointer_fd.c \
				print${DIRSEP}ft_putnbr_fd.c \
				print${DIRSEP}ft_putnbr_unsigned_fd.c \
				print${DIRSEP}ft_putnbr_base_fd.c \
				utils${DIRSEP}ft_strlen.c

SRCS_UNIT	= unit_test.c

OBJS		= $(addprefix src${DIRSEP}, ${SRCS:%.c=%.o})

OBJS_UNIT	= $(addprefix unitests${DIRSEP}, ${SRCS_UNIT:%.c=%.o})

CC			= gcc

HEAD		= includes

CFLAGS		= -Wall -Wextra -Werror -I ${HEAD}

%.o : %.c
	${CC} ${CFLAGS} -o $@ -c $<

${NAME}: ${OBJS} ${HEAD}
	ar crs ${NAME} ${OBJS}

all: ${NAME}

clean: 
	${RM} ${OBJS}
	${RM} ${OBJS_UNIT}

fclean: clean
	${RM} ${NAME}

re: fclean all

unitest: all ${OBJS_UNIT}
	${CC} ${CFLAGS} -o ${NAME_UNIT} ${OBJS_UNIT} ${NAME}
	./${NAME_UNIT}

.PHONY: all clean fclean re unitest