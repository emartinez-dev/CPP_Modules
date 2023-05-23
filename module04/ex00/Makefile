# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 15:30:23 by franmart          #+#    #+#              #
#    Updated: 2023/05/23 11:51:17 by franmart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= polymorphism

CC			= clang++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
RM 			= rm -rf

SRCSDIR		= ./

SRCS		=	Animal.cpp\
				Dog.cpp\
				Cat.cpp\
				WrongCat.cpp\
				WrongAnimal.cpp\
				main.cpp

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

.PHONY: all clean fclean re
