PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o NumArray.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

NumArray.o : NumArray.cpp
	$(CC) $(CPPFLAGS) -c NumArray.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make