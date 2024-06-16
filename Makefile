# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okoca <okoca@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 19:32:31 by okoca             #+#    #+#              #
#    Updated: 2024/06/16 17:08:15 by okoca            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL=  /bin/bash

MAKEFLAGS += --no-print-directory

Black           =   $(shell echo -e "\033[0;30m")
FBlack          =   $(shell echo -e "\033[1;30m")
Red             =   $(shell echo -e "\033[0;31m")
FRed            =   $(shell echo -e "\033[1;31m")
Green           =   $(shell echo -e "\033[0;32m")
FGreen          =   $(shell echo -e "\033[1;32m")
Brown/Orange    =   $(shell echo -e "\033[0;33m")
FBrown/Orange   =   $(shell echo -e "\033[1;33m")
FYellow         =   $(shell echo -e "\033[1;33m")
Yellow          =   $(shell echo -e "\033[0;33m")
Blue            =   $(shell echo -e "\033[0;34m")
FBlue           =   $(shell echo -e "\033[1;34m")
Purple          =   $(shell echo -e "\033[0;35m")
FPurple         =   $(shell echo -e "\033[1;35m")
Cyan            =   $(shell echo -e "\033[0;36m")
FCyan           =   $(shell echo -e "\033[1;36m")
FWhite          =   $(shell echo -e "\033[1;37m")
White           =   $(shell echo -e "\033[0;37m")
RESET           =   $(shell echo -e "\033[0m")
TICK            =   $(shell echo -e "\xE2\x9C\x94")

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
			check_utils.c \
			debug.c \
			key.c \
			render.c

NAME = so_long

SRC = ${addprefix ${SRC_DIR}, ${SRC_FILES}}

OBJS = ${SRC:.c=.o}

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS} ${MLX_TARGET} ${LIBFT_TARGET}
	@echo "$$BANNER"
	@echo -e "${FRed}\n>>>Building ${FPurple}${NAME}${RESET}${Red}...${RESET}"
	@${CC} ${CFLAGS} ${OBJS} ${LDFLAGS} -o ${NAME}
	@echo "${FGreen}   Done [${TICK}]"


all: ${NAME}


${MLX_TARGET}:
	@echo -e "\n$(FYellow)#################$(FRed) Building ${FPurple}$(MLX) $(FYellow)##################\n"
	@make -C ${MLX}
	@echo -e "${FGreen}                     Done [${TICK}]\n"
	@echo "$(FYellow)------------------------------------------------------"

${LIBFT_TARGET}:
	@echo -e "\n$(FYellow)##################$(FRed) Building ${FPurple}$(LIBFT) $(FYellow)###################\n"
	@make -C ${LIBFT}
	@echo -e "${FGreen}                     Done [${TICK}]\n"
	@echo "$(FYellow)------------------------------------------------------"

clean:
	@echo "$(FRed)Cleaning $(MLX)$(FGreen)             [$(TICK)]"
	@echo "$(FRed)Cleaning $(LIBFT)$(FGreen)                [$(TICK)]"
	@echo "$(FRed)Cleaning $(NAME)$(FGreen)              [$(TICK)]"
	@make clean -C ${MLX}
	@make clean -C ${LIBFT}
	@rm -f ${OBJS}

fclean: clean
	@echo "$(FRed)Full Cleaning $(NAME)$(FGreen)         [$(TICK)]"
	@echo "$(FRed)Full Cleaning $(LIBFT)$(FGreen)           [$(TICK)]"
	@make fclean -C ${LIBFT}
	@rm -f ${NAME}
	@echo "$(FYellow)------------------------------------------------------"

define BANNER
${FRed}     ___         ___                     ___         ___         ___     ${RESET}
${FRed}    /  /\       /  /\                   /  /\       /__/\       /  /\    ${RESET}
${FRed}   /  /:/_     /  /::\                 /  /::\      \  \:\     /  /:/_   ${RESET}
${FRed}  /  /:/ /\   /  /:/\:\  ___     ___  /  /:/\:\      \  \:\   /  /:/ /\  ${RESET}
${FRed} /  /:/ /::\ /  /:/  \:\/__/\   /  /\/  /:/  \:\ _____\__\:\ /  /:/_/::\ ${RESET}
${FRed}/__/:/ /:/\:/__/:/ \__\:\  \:\ /  /:/__/:/ \__\:/__/::::::::/__/:/__\/\:\${RESET}
${FRed}\  \:\/:/~/:\  \:\ /  /:/\  \:\  /:/\  \:\ /  /:\  \:\~~\~~\\  \:\ /~~/:/${RESET}
${FRed} \  \::/ /:/ \  \:\  /:/  \  \:\/:/  \  \:\  /:/ \  \:\  ~~~ \  \:\  /:/ ${RESET}
${FRed}  \__\/ /:/   \  \:\/:/    \  \::/    \  \:\/:/   \  \:\      \  \:\/:/  ${RESET}
${FRed}    /__/:/     \  \::/      \__\/      \  \::/     \  \:\      \  \::/   ${RESET}
${FRed}    \__\/       \__\/                   \__\/       \__\/       \__\/    ${RESET}
${FRed}
endef
export BANNER

re: fclean all

.PHONY: all clean fclean re
