# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtanigaw <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 08:18:15 by dtanigaw          #+#    #+#              #
#    Updated: 2022/07/06 08:18:23 by dtanigaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	 E X E C U T A B L E  N A M E	 #

NAME				=	brain

#			C C  F L A G S			  #

CXX					=	c++
CXXFLAGS			=	-Wall -Werror -Wextra -std=c++98
INC					=	-I inc/

#######################################
#				F I L E S			  #
#######################################

#		S O U R C E  F I L E S		  #

SRC_DIR				=	src/
SRC_FILES			=	main.cpp \
						Animal.cpp \
						Cat.cpp \
						Dog.cpp \
						Brain.cpp
SRC					=	$(addprefix $(SRC_DIR), $(SRC_FILES))


#			O B J .  F I L E S		  #

OBJ_DIR				=	obj/
OBJ_FILES			=	$(SRC_FILES:.cpp=.o)
OBJ					=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

#			I N C .  F I L E S		  #

INC_DIR				=	inc/
INC_FILES			=	Animal.hpp \
						Cat.hpp \
						Dog.hpp \
						Brain.hpp
INCS				=	$(addprefix $(INC_DIR), $(INC_FILES))

#######################################
#				R U L E S			  #
#######################################

#		  B U I L D  R U L E S		  #

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(INCS)
	mkdir -p $(OBJ_DIR)
	$(CXX) $(INC) $(CXXFLAGS) -o $@ -c $<


# C L E A N  &  O T H E R  R U L E S  #

RM = rm -rf

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
