all: live0 live1 live2 live3 live4 live5 live6 live7 live8 live9

CXXFLAGS=-Wall -Wextra
CFLAGS=-std=c99 -Wall -Wextra -Wstrict-prototypes -Wmissing-prototypes

.PHONY: clean
clean:
	rm -f -- live0 live1 live2 live3 live4 live5 live6 live7 live8 live9

live0: main0.cpp live0.cpp live0.h
	g++ $(CXXFLAGS) -o $@ main0.cpp live0.cpp

live1: main1.cpp live1.cpp live1.h
	g++ $(CXXFLAGS) -o $@ main1.cpp live1.cpp

live2: main2.cpp live2.cpp live2.h
	g++ $(CXXFLAGS) -o $@ main2.cpp live2.cpp

live3: main3.cpp live3.cpp live3.h
	g++ $(CXXFLAGS) -o $@ main3.cpp live3.cpp

live4: main4.cpp live4.cpp live4.h
	g++ $(CXXFLAGS) -o $@ main4.cpp live4.cpp

live5: main5.cpp live5.cpp live5.h
	g++ $(CXXFLAGS) -o $@ main5.cpp live5.cpp

live6: main6.c live6.c live6.h
	gcc $(CFLAGS) -o $@ main6.c live6.c

live7: main7.c live7.c live7.h
	gcc $(CFLAGS) -o $@ main7.c live7.c

live8: main8.c live8.c live8.h
	gcc $(CFLAGS) -o $@ main8.c live8.c

live9: main9.c live9.c live9.h
	gcc $(CFLAGS) -o $@ main9.c live9.c
