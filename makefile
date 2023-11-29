SRCS=hexview.c \
	 another_tohex.c \
	 get_size_file.c \
	 help.c \
	 print_elements.c
OBJS=$(SRCS:.c=.o)


all: HexView

HexView: $(OBJS)
	gcc $(OBJS) -o HexView

hexview.o: hexview.c
	gcc -c hexview.c

another_tohex.o: another_tohex.c
	gcc -c another_tohex.c

get_size_file.o: get_size_file.c
	gcc -c get_size_file.c

help.o: help.c
	gcc -c help.c

print_elements.o: print_elements.c
	gcc -c print_elements.c

clean:
	rm -rf *.o HexView
