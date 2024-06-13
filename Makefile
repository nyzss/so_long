# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okoca <okoca@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 19:32:31 by okoca             #+#    #+#              #
#    Updated: 2024/06/13 13:30:32 by okoca            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

SRC_DIR = src/

INCLUDES_DIR = includes

LIBFT = libft

CFLAGS = -Wall -Werror -Wextra -I${INCLUDES_DIR} -I${LIBFT} -g

LDFLAGS = -L${LIBFT} -lft

LIBFT_TARGET = ${LIBFT}/libft.a

SRC_FILES = main.c

NAME = so_long

SRC = ${addprefix ${SRC_DIR}, ${SRC_FILES}}

OBJS = ${SRC:.c=.o}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

# ${NAME}: ${OBJS} ${LIBFT_TARGET}
# 	${CC} ${CFLAGS} ${OBJS} ${LDFLAGS} -o ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all: ${NAME}

${LIBFT_TARGET}:
	make -C ${LIBFT}

clean:
#	make clean -C ${LIBFT}
	rm -f ${OBJS}

fclean: clean
#	 make fclean -C ${LIBFT}
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
