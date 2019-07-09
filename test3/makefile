YACC=yacc
CC=g++
OBJECT=ret

$(OBJECT)	:	scanner.o y.tab.o datastruct.o
	$(CC) main.cpp scanner.o y.tab.o datastruct.o -o $(OBJECT) -std=c++11
scanner.o 	:	scanner.cpp y.tab.h
	$(CC) -c scanner.cpp -std=c++11
datastruct.o 	:	datastruct.cpp
	$(CC) -c datastruct.cpp -std=c++11
y.tab.o  :	y.tab.c 
	$(CC) -c y.tab.c -std=c++11
y.tab.c y.tab.h	:	yacc.y
	$(YACC) -d yacc.y
clean:
	rm -f $(OBJECT) *.o