Worm : test.o Parser.o NetBug.o Hooker.o SpecParser.o
	g++ -std=c++11 -o Worm test.o Parser.o NetBug.o Hooker.o SpecParser.o -lcurl -lhtmlcxx 

test.o : test.cpp Hooker.h Parser.h NetBug.h

Parser.o : Parser.cpp Parser.h

Hooker.o : Hooker.cpp Hooker.h

NetBug.o : NetBug.cpp NetBug.h

SpecParser.o : SpecParser.cpp SpecParser.h


clean :
		rm *.o Worm
