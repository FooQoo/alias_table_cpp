CC = g++
CFLAGS = -g -Wall
OBJS = main.o alias_table.o rn_gen.o

ALL: main.o alias_table.o rn_gen.o
	$(CC) $(CFLAGS) -o main main.o alias_table.o rn_gen.o

main.o: ./src/main.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

alias_table.o: ./src/alias_table.cpp ./src/alias_table.h
	$(CC) $(CFLAGS) -o $@ -c $<

rn_gen.o: ./src/rn_gen.cpp ./src/rn_gen.h
	$(CC) $(CFLAGS) -o $@ -c $<

clean: 
	rm -rf $(OBJS)