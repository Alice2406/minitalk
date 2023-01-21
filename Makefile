# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/08 16:25:39 by aniezgod          #+#    #+#              #
#    Updated: 2023/01/21 09:35:50 by aniezgod         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## ----------------------------------COLORS------------------------------------#

BOLD = \e[1;37m
END = \e[0;37m
UNDER = \e[4;37m
GREY = \e[0;30m
RED = \e[0;31m
GREEN = \e[0;32m
YELLOW = \e[0;33m
BLUE = \e[0;34m
PURPLE = \e[0;35m
CYAN = \e[0;36m
WHITE = \e[0;37m

## ----------------------------------NAME------------------------------------- ##
SERVER_NAME	= server
CLIENT_NAME	= client

SRC_SERVER = ./srcs/server.c
SRC_CLIENT = ./srcs/client.c

OBJ_SERVER = ${SRC_SERVER:.c=.o}
OBJ_CLIENT = ${SRC_CLIENT:.c=.o}

CC = clang
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
INCS = -I ./includes/ -I ./libft/includes/

.c.o:
				@${CC} ${CFLAGS} ${INCS} -c $< -o $@

all:	${SERVER_NAME} ${CLIENT_NAME}

## ------------------------------COMPILATION---------------------------------- ##
${SERVER_NAME}: ${OBJ_SERVER}
			@printf "${WHITE}${BOLD}╔════════════════════════════════════════════════════════════════════════════╗\n"
			@printf "${BOLD}║                              .: COMPILATION :.                             ║\n"
			@printf "${BOLD}╚════════════════════════════════════════════════════════════════════════════╝\n"
			@${MAKE} -C ./libft >/dev/null
			@printf "${BOLD}║                                    ${PURPLE}libft                                   ${WHITE}║\n"			
			@${CC} -g ${CFLAGS} -o ${SERVER_NAME} ${OBJ_SERVER} libft/libft.a ${INCS}
			@printf "${BOLD}║                                    ${PURPLE}server                                  ${WHITE}║\n"

${CLIENT_NAME}: ${OBJ_CLIENT}
			@${CC} -g ${CFLAGS} -o ${CLIENT_NAME} ${OBJ_CLIENT} libft/libft.a ${INCS}
			@printf "${BOLD}║                                    ${PURPLE}client                                  ${WHITE}║\n"
			@printf "${BOLD}╚════════════════════════════════════════════════════════════════════════════╝\n"
			
## -------------------------------NETTOYAGE------------------------------------ ##

clean:
			@${RM} ${OBJ_CLIENT} ${OBJ_SERVER}
			@${MAKE} -C libft clean >/dev/null
			
fclean: clean
			@printf "${BOLD}Entreprise de nettoyage bonjour ?\n"
			@${RM} ${CLIENT_NAME} ${SERVER_NAME}
			@${MAKE} -C libft fclean >/dev/null
			@printf "${BOLD}${GREEN}Tout est propre !✨\n"

re: fclean all

.PHONY:		all clean fclean re