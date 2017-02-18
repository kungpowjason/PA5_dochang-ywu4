# Make file for PA5
# Written by: Yu-sen Wu (1/30/17)
OBJS = PA5.o Rational.o
CFLAGS = -g -Wall

PA5: $(OBJS)
	g++ $(CFLAGS) $(OBJS) -o PA5
	
PA5.o: PA5.cpp Rational.h Rational.cpp
	g++ $(CFLAGS) -c PA5.cpp Rational.cpp
	
Rational.o: Rational.h Rational.cpp
	g++ $(CFLAGS) -c Rational.cpp

clean:
	rm -f *.o PA5

all: PA5