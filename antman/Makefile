##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

NAME	=	antman

CC		=	gcc -g3
RM		=	rm -rf

SRC		=	$(shell find src -type f -name "*.c")

OBJ		=	$(SRC:.c=.o)

LIB		=	-L../lib/my -lmy -lm -I../include

WARN1	=	-W -Wall -Wextra -Wpedantic -Wformat-nonliteral -Wformat-signedness
WARN2	=	-Wconversion -Wunsuffixed-float-constants -Wmissing-prototypes
WARN3	=	-Wunused-macros -Warith-conversion -Wmissing-include-dirs

$(NAME):
		@make -s -C ../lib/my
		@$(CC) -o $(NAME) $(SRC) $(WARN1) $(WARN2) $(WARN3) $(LIB)
		@rm ../lib/libmy.a
		@rm ../lib/my/libmy.a
		@make -s clean

all:	$(NAME)

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
