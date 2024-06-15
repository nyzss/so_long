# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okoca <okoca@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 19:32:31 by okoca             #+#    #+#              #
#    Updated: 2024/06/15 10:41:48 by okoca            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

SRC_DIR = src/

INCLUDES_DIR = includes

MLX= minilibx

LIBFT = libft

CFLAGS = -Wall -Werror -Wextra -I${INCLUDES_DIR} -I${MLX} -I${LIBFT} -g

LDFLAGS = -L${MLX} -L${LIBFT} -lmlx_Linux -lXext -lX11 -lm -lbsd -lft

LIBFT_TARGET = ${LIBFT}/libft.a

MLX_TARGET = ${MLX}/libmlx.a

SRC_FILES = main.c \
			utils.c \
			map.c \
			parse.c \
			check.c \
			check_closed.c \
			flood_fill.c \
			init.c \
			check_utils.c

NAME = so_long

SRC = ${addprefix ${SRC_DIR}, ${SRC_FILES}}

OBJS = ${SRC:.c=.o}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS} ${MLX_TARGET} ${LIBFT_TARGET}
	${CC} ${CFLAGS} ${OBJS} ${LDFLAGS} -o ${NAME}

all: ${NAME}

${MLX_TARGET}:
	make -C ${MLX}

${LIBFT_TARGET}:
	make -C ${LIBFT}

clean:
	make clean -C ${MLX}
	make clean -C ${LIBFT}
	rm -f ${OBJS}

fclean: clean
	make fclean -C ${LIBFT}
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
