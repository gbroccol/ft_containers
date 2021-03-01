# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/01 11:32:12 by gbroccol          #+#    #+#              #
#    Updated: 2021/03/01 12:36:26 by gbroccol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME = ft_containers

# # SHELL = /bin/sh

# # B&W = \033[0;0m
# # RED  = \033[0;31m
# # GREEN = \033[0;32m
# # PURPLE = \033[0;35m

# CC = clang++
# STD = -std=c++98
# CFLAGS = -Wall -Werror -Wextra -g 				# -g _________________________
# RM = rm - rf

# SRCS =			main.cpp \ 
# 				list_test.cpp \ 
# 				map_test.cpp \ 
# 				queue_test.cpp \ 
# 				stack_test.cpp \ 
# 				vector_test.cpp

# OBJ =			$(SRCS:.cpp=.o)

# %.o: %.cpp
# 			$(CC) $(FLAGS) $(STD) -c $< -o $@

# all: $(NAME)

# $(NAME): $(OBJ)
# 			$(CC) $(FLAGS) $(OBJ) -o $(NAME)
			
# clean:
# 			rm -rf $(OBJ)
			
# fclean:
# 			rm -rf $(OBJ) $(NAME)

# re: fclean all

# .PHONY: all clean fclean re



NAME =		ft_containers

CC =		clang++

FLAGS =		-Wall -Werror -Wextra -std=c++98

# HEADER = /.

SRCS =		test/main.cpp \
			test/list_test.cpp \
			test/map_test.cpp \
			test/queue_test.cpp \
			test/stack_test.cpp \
			test/vector_test.cpp \
			
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