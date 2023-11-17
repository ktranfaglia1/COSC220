PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o Coin.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

CircleClassv1.o : Coin.cpp
	$(CC) $(CPPFLAGS) -c Coin.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make