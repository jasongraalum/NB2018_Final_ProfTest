# Define required macros here
SHELL = /bin/sh

OBJS =  MemBlock.o MemList.o
CFLAG = -Wall
CC = g++
INCLUDE =


MemList: MemList.cpp MemList.hpp MemBlock
	${CC} ${CFLAGS} ${INCLUDES} -c MemList.cpp

MemBlock: MemBlock.cpp MemBlock.hpp 
	${CC} ${CFLAGS} ${INCLUDES} -c MemBlock.cpp

level0: memtest.cpp MemList
	${CC} ${CFLAGS} ${INCLUDES} -o memtest memtest.cpp ${OBJS}
	./memtest 0 

level1: memtest.cpp MemList
	${CC} ${CFLAGS} ${INCLUDES} -o memtest memtest.cpp ${OBJS}
	./memtest 1 

level2: memtest.cpp MemList
	${CC} ${CFLAGS} ${INCLUDES} -o memtest memtest.cpp ${OBJS}
	./memtest 2 

level3: memtest.cpp MemList
	${CC} ${CFLAGS} ${INCLUDES} -o memtest memtest.cpp ${OBJS}
	./memtest 3 

all: level0 level1 level2 level3

clean:
	-rm -f *.o *.s *.ii 

