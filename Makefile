COMPILE=gcc
STD=-std=c99 
CFLAGS=-Wall -Werror -Wextra -pedantic


make: update_locations.c
	$(COMPILE) $(STD) $(CFLAGS) -o update_locations update_locations.c

clean:
	rm update_locations