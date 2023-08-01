# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 16:00:28 by franmart          #+#    #+#              #
#    Updated: 2023/08/01 19:50:53 by franmart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= intern

CC			= clang++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
RM 			= rm -rf

SRCSDIR		= ./
INCLUDES	= ./

SRCS		= AForm.cpp\
			  ShrubberyCreationForm.cpp\
			  PresidentialPardonForm.cpp\
			  RobotomyRequestForm.cpp\
			  Bureaucrat.cpp\
			  Intern.cpp\
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
