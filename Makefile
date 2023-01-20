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

NAME = libftprintf.a

SRC_DIR = src

SRCS = ${SRC_DIR}${DIRSEP}ft_isflag.c \
       ${SRC_DIR}${DIRSEP}ft_isflag.o \
       ${SRC_DIR}${DIRSEP}ft_printchar.c \
       ${SRC_DIR}${DIRSEP}ft_printf.c \
       ${SRC_DIR}${DIRSEP}ft_printf.o \
       ${SRC_DIR}${DIRSEP}ft_printflag.c \
       ${SRC_DIR}${DIRSEP}ft_printhex.c \
       ${SRC_DIR}${DIRSEP}ft_printnbr.c \
       ${SRC_DIR}${DIRSEP}ft_printptr.c \
       ${SRC_DIR}${DIRSEP}ft_printstr.c \
       ${SRC_DIR}${DIRSEP}ft_printunsigned.c \

OBJS 	= $(SRCS:.c=.o)

CC		= gcc

CFLAGS 	= -Wall -Wextra -Werror

all: $(NAME)

libft:
	make -C libft

$(NAME): libft $(OBJS)
	ar rcs ${NAME} ${OBJS} libft/libft.a

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	make -C libft clean
	${RM} -f ${OBJS}

fclean: clean
	make -C libft fclean
	${RM} -f ${NAME}

re: fclean all

.PHONY: libft all clean fclean re