CC = clang++
CFLAGS = -std=c++17 -pedantic -pedantic-errors -Wall -Werror -Wextra
LDFLAGS = -lm
SOURCES = main.cpp asm.cpp mem.cpp ops.cpp reg.cpp val.cpp parser.cpp
HEADERS = asm.h mem.h ops.h reg.h val.h parser.h
STYLE = Google
FORMAT_FLAGS = -i --sort-includes

all: main.out reformat run

run:
	@./main.out

reformat:
	@clang-format $(FORMAT_FLAGS) --style=$(STYLE) $(SOURCES) $(HEADERS)

main.out: main.cpp
	@$(CC) $(CFLAGS) $(LDFLAGS) $(SOURCES) -o main.out

clean:
	$(RM) main.out

memcheck:
	@valgrind --leak-check=full ./main.out

.PHONY: run all reformat
