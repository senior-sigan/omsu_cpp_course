CC = clang
CFLAGS = -pedantic -pedantic-errors -Wall -Werror -Wextra -Wno-unused-parameter
LDFLAGS = -lm
SOURCES = main.c array_list.c linked_list.c list.h
STYLE = Google

.PHONY: all
all: reformat clean
	@echo "Кнопка RUN не работает"
	@echo "Для запуска программы напишите в консоли"
	@echo "make run_array_list"
	@echo "make run_linked_list"

run_array_list: reformat array_list
	./array_list

run_linked_list: reformat linked_list
	./linked_list

array_list.o: array_list.c list.h
	$(CC) $(CFLAGS) -c array_list.c

linked_list.o: linked_list.c list.h
	$(CC) $(CFLAGS) -c linked_list.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

array_list: main.o array_list.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o array_list main.o array_list.o

linked_list: main.o linked_list.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o linked_list main.o linked_list.o

.PHONY: reformat
reformat:
	clang-format -i --style=$(STYLE) $(SOURCES)

.PHONY: clean
clean:
	$(RM) linked_list array_list *.o *~