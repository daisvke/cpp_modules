#	 E X E C U T A B L E  N A M E	 #

NAME				=	megaphone

#			C C  F L A G S			  #

CC					=	c++
CFLAGS				=	-Wall -Werror -Wextra -std=c++98


#######################################
#				F I L E S			  #
#######################################

#		S O U R C E  F I L E S		  #

SRC_DIR				=	./
SRC_FILES			=	megaphone.cpp
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
	$(CC) $(CFLAGS) -o $@ -c $<


# C L E A N  &  O T H E R  R U L E S  #

RM = rm -rf

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re


