# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 16:00:28 by franmart          #+#    #+#              #
#    Updated: 2023/08/30 12:56:17 by franmart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= RPN

CC			= clang++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
RM 			= rm -rf

SRCSDIR		= ./
INCLUDES	= ./

SRCS		= main.cpp\
			  RPN.cpp

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
	@echo "_______Testing subject cases________\n"
	./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
	@echo "\n"
	./RPN "7 7 * 7 -"
	@echo "\n"
	./RPN "1 2 * 2 / 2 * 2 4 - +"
	@echo "\n"
	./RPN "(1 + 1)"
	@echo "\n______Testing more corner cases_______\n"
	@echo "Not enough operands:\n"
	./RPN "1 + "
	@echo "\nStack not clear:\n"
	./RPN "1 4 3 + "
	@echo "\nToo many args:\n"
	./RPN "1 4 3 + " "1 1 +"
	
.PHONY: all clean fclean re test

