NAME	= answer
CC		= clang++
CFLAGS	= -std=c++98 -Wall -Wextra -Werror

all: $(NAME)

$(NAME): main.o
	$(CC) $< -o $@

main.o: main.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f main.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
