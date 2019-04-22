##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

NAME	= 110borwein

CC	= gcc -lm


RM	= rm -f

SRCS	= 	110_borwein.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include

all: $(NAME)

##tests_run:
##				cd tests/ && $(MAKE)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re tests_run
