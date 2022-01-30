##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## program
##

SRC	=	main.cpp		\
		Component/Component4001.cpp		\
		Component/Component4011.cpp		\
		Component/Component4030.cpp		\
		Component/Component4069.cpp		\
		Component/Component4071.cpp		\
		Component/Component4081.cpp		\
		Component/Input.cpp		\
		Component/Output.cpp		\
		Circuit.cpp		\
		Pin.cpp		\
		Factory.cpp		\
		Parser.cpp		\
		AComponent.cpp	\
		Nano.cpp		\
		Component/True.cpp		\
		Component/False.cpp		\
		Component/Clock.cpp

NAME	=	nanotekspice

FLAGS	=	-W -Wall -Werror -Wextra -Wunused-macros -Wendif-labels -pedantic -Wcomment -Wmissing-braces -Wmissing-include-dirs -Wparentheses -Wsequence-point -ansi -ggdb -Wunused -Wduplicated-branches -Wmisleading-indentation

all:	$(NAME)

$(NAME):
		g++ -o $(NAME) $(SRC)

valgrind:
		g++ -o $(NAME) $(SRC) -g3

warning:
		g++ -o $(NAME) $(SRC) $(FLAGS) -g3

optimize:
		g++ -o $(NAME) $(SRC) -O4

clean:
		rm -f $(NAME)

fclean:
		rm -f $(NAME)
		rm -f *~
		rm -f *#

re:		fclean all
