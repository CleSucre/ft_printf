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
	RM		= del -f
	MOVE	= move
else
	DIRSEP	= /
	RM		= rm -f
	MOVE	= mv
endif

NAME = libftprintf.a

SRC_DIR = src

SRCS = ${SRC_DIR}${DIRSEP}ft_printf.c \
       ${SRC_DIR}${DIRSEP}ft_printflag.c \
       ${SRC_DIR}${DIRSEP}ft_puthex_fd.c \
       ${SRC_DIR}${DIRSEP}ft_putunsigned_fd.c \

OBJS 	= $(SRCS:.c=.o)

CC		= gcc

CFLAGS 	= -Wall -Wextra -Werror

all: $(NAME)

libft.a:
	make -C .${DIRSEP}libft

$(NAME): libftprintf.a $(OBJS)
	${MOVE} libft${DIRSEP}libft.a ${NAME}
	ar rcs ${NAME} ${OBJS}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	make -C .${DIRSEP}libft clean
	${RM} ${OBJS}

fclean: clean
	make -C .${DIRSEP}libft fclean
	${RM} ${NAME}

re: fclean all

.PHONY: libft all clean fclean re