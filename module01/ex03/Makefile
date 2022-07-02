# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtanigaw <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/02 22:02:48 by dtanigaw          #+#    #+#              #
#    Updated: 2022/07/02 22:03:08 by dtanigaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	 E X E C U T A B L E  N A M E	 #

NAME				=	fight

#			C C  F L A G S			  #

CC					=	c++
CFLAGS				=	-Wall -Werror -Wextra -std=c++98
INC					=	-I inc/

#######################################
#				F I L E S			  #
#######################################

#		S O U R C E  F I L E S		  #

SRC_DIR				=	src/
SRC_FILES			=	main.cpp \
						HumanA.cpp \
						HumanB.cpp \
						Weapon.cpp
SRC					=	$(addprefix $(SRC_DIR), $(SRC_FILES))


#			O B J .  F I L E S		  #

OBJ_DIR				=	obj/
OBJ_FILES			=	$(SRC_FILES:.cpp=.o)
OBJ					=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))


#######################################
#				R U L E S			  #
#######################################

#		  B U I L D  R U L E S		  #

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(INC) $(C_FLAGS) -o $@ -c $<


# C L E A N  &  O T H E R  R U L E S  #

RM = rm -rf

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re


