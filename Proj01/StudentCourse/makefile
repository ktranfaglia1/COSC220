PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o Course.o Student.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

Course.o : Course.h Course.cpp
	$(CC) $(CPPFLAGS) -c Course.cpp
	
Student.o : Student.h Student.cpp
	$(CC) $(CPPFLAGS) -c Student.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make