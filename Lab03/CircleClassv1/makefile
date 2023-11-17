PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o Circle.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

CircleClassv1.o : Circle.cpp
	$(CC) $(CPPFLAGS) -c Circle.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make