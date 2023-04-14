##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC = $(shell echo src/*.c)

OBJ = $(SRC:.c=.o)

NAME = matchstick

all: $(NAME)

$(NAME):$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -rf src/*.o
	rm -rf src/*.c~
	rm -rf include/*.h~
	rm -rf Makefile~
	rm -rf matchstick

fclean:
	clean
	rm -f $(NAME)

re: fclean all
