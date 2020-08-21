CC = clang
CFLAGS = -pedantic -pedantic-errors -Wall -Werror -Wextra
LDFLAGS = -lm
SOURCES = main.c

all: main.out reformat run

run:
	./main.out

reformat:
	clang-format -i --style=Google $(SOURCES)

main.out: main.c
	$(CC) $(CFLAGS) $(LDFLAGS) $(SOURCES) -o main.out

.PHONY = run all reformat
