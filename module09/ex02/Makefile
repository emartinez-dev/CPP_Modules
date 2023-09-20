# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 16:00:28 by franmart          #+#    #+#              #
#    Updated: 2023/09/20 16:01:32 by franmart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= PmergeMe

CC			= clang++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
RM 			= rm -rf

SRCSDIR		= ./
INCLUDES	= ./

SRCS		= main.cpp\
			  PmergeMe.cpp

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

test: $(NAME)
	./$(NAME) `jot 10 1 10 | sort -R | tr '\n' ' '` | less
	./$(NAME) `jot 100 1 100 | sort -R | tr '\n' ' '` | less
	./$(NAME) `jot 3000 1 3000 | sort -R | tr '\n' ' '` | less

.PHONY: all clean fclean re test

