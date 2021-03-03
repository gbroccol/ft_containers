# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/01 11:32:12 by gbroccol          #+#    #+#              #
#    Updated: 2021/03/03 19:58:39 by gbroccol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		ft_containers

CC =		clang++

FLAGS =		-Wall -Werror -Wextra -std=c++98

# HEADER = /.

SRCS =		main.cpp \
			list_test.cpp \
			map_test.cpp \
			queue_test.cpp \
			stack_test.cpp \
			vector_test.cpp \
			
OBJ =		$(SRCS:.cpp=.o)

%.o: %.cpp
			$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)
$(NAME): $(OBJ)
			$(CC) $(FLAGS) $(OBJ) -o $(NAME)
clean:
			rm -rf $(OBJ)
fclean:
			rm -rf $(OBJ) $(NAME)
re: fclean all

.PHONY: all clean fclean re