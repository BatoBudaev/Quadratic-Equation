CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -c -g
OS := $(shell uname)
TEST_FLAGS = $(shell pkg-config --cflags --libs check) -lm

all: check

check: clean test

test: test_quadratic_equation.o quadratic_equation.a
	$(CC) test_quadratic_equation.o quadratic_equation.a -o test -L. $(TEST_FLAGS)
	./test

test_quadratic_equation.o: test_quadratic_equation.c
	$(CC) $(CFLAGS) test_quadratic_equation.c -o test_quadratic_equation.o

quadratic_equation.a: quadratic_equation.o
	ar rcs quadratic_equation.a quadratic_equation.o
	ranlib quadratic_equation.a

quadratic_equation.o: quadratic_equation.c
	$(CC) $(CFLAGS) quadratic_equation.c -o quadratic_equation.o

clean:
	rm -rf *.o *.a *.out *.info *.html *.gc* test

leak:
ifeq ($(OS),Darwin)
	CK_FORK=no leaks -atExit -- ./test
else
	valgrind --leak-check=full -s --track-origins=yes ./test
endif

rebuild: all