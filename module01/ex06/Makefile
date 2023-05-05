# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 15:30:23 by franmart          #+#    #+#              #
#    Updated: 2023/05/05 15:02:23 by franmart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= harlFilter

CC			= clang++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
RM 			= rm -rf

SRCSDIR		= ./
INCLUDES	=	Harl.hpp


SRCS		=	main.cpp\
				Harl.cpp

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
	@echo "--------------------------------------------------------------------"
	@echo "\nTesting an empty or invalid filter. It should show the special message \n"
	./${NAME} ""
	@echo "--------------------------------------------------------------------"
	@echo "\nTesting an error filter. It should only show one message\n"
	./${NAME} "ERROR"
	@echo "--------------------------------------------------------------------"
	@echo "\nTesting a warning filter. It should show two messages\n"
	./${NAME} "WARNING"
	@echo "--------------------------------------------------------------------"
	@echo "Testing an info filter. It should show three messages\n"
	./${NAME} "INFO"
	@echo "--------------------------------------------------------------------"
	@echo "Testing a debug filter. It should show the 4 messages\n"
	./${NAME} "DEBUG"
	@echo "--------------------------------------------------------------------"

.PHONY: all clean fclean re test
