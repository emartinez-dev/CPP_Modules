# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 15:30:23 by franmart          #+#    #+#              #
#    Updated: 2023/05/05 11:19:38 by franmart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= sed_is_for_losers

CC			= clang++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
RM 			= rm -rf

SRCSDIR		= ./
INCLUDES	=	sed2.hpp


SRCS		=	main.cpp\
				sed2.cpp

SRC 		= ${addprefix ${SRCSDIR}, ${SRCS}}
OBJ 		= ${SRC:.cpp=.o}

$(NAME): $(OBJ)
		@echo "Compiling $(NAME)..."
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	${CC} ${CFLAGS} -c $^ -o $@

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all

test: all
	@echo "Downloading el Quijote..."
	@curl "https://gist.githubusercontent.com/jsdario/6d6c69398cb0c73111e49f1218960f79/raw/8d4fc4548d437e2a7203a5aeeace5477f598827d/el_quijote.txt" | fold -sw 80 > el_quijote.txt
	@./$(NAME) el_quijote.txt "Quijote" "Joaquín"
	@colordiff el_quijote.txt el_quijote.txt.replace
	@rm el_quijote.txt el_quijote.txt.replace

.PHONY: all clean fclean re test
