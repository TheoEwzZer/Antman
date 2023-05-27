##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

NAME	=	main

$(NAME):
		@make -s re -C antman
		@make -s re -C giantman
		@make -s clean

all:	$(NAME)

clean:
		@make -s clean -C antman
		@make -s clean -C giantman

fclean:	clean
		@make -s fclean -C antman
		@make -s fclean -C giantman

re:    fclean all
