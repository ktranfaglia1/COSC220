PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o Month.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

Month.o : Month.cpp
	$(CC) $(CPPFLAGS) -c Month.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make