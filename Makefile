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

NAME_UNIT	= unit_test.out

SRCS		= ft_printf.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putpointer_fd.c \
				ft_putnbr_fd.c \
				ft_putnbr_unsigned_fd.c \
				ft_putnbr_base_fd.c \
				ft_strlen.c

SRCS_UNIT	= unit_test.c

OBJS		= $(addprefix src${DIRSEP}, ${SRCS:%.c=%.o})

OBJS_UNIT	= $(addprefix unitests${DIRSEP}, ${SRCS_UNIT:%.c=%.o})

CC			= cc

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
	${RM} ${NAME_UNIT}

re: fclean all

unitest: all ${OBJS_UNIT}
	${CC} -o ${NAME_UNIT} ${OBJS_UNIT} ${NAME}
	./${NAME_UNIT}

.PHONY: all clean fclean re unitest