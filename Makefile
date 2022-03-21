##
# Brabant Simulator
#
NAME = brabant-simulator
VERSION = 1.0
CC = gcc
LINKEN = -lraylib
CFLAGS = -g -Wall -Wextra -Werror
CFILES = src/*

$(NAME):
	$(CC) $(CLAGS) $(CFLAGS) $(LINKEN) $(CFILES) -o $(NAME)

test: re
	./brabant-simulator

re: clean $(NAME)

clean:
	rm -f $(NAME)

# end
