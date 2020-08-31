CC = clang
CFLAGS = -pedantic -pedantic-errors -Wall -Werror -Wextra
LDFLAGS = -lm
SOURCES = main.c
STYLE = Google

all: main reformat run

run:
	./main

reformat:
	clang-format -i --style=$(STYLE) $(SOURCES)

main.out: main.c
	$(CC) $(CFLAGS) $(LDFLAGS) $(SOURCES) -o main

.PHONY = run all reformat
