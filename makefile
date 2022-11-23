AsciiArtTool: RLEList.o AsciiArtTool.o main.o
	gcc -DNDEBUG AsciiArtTool.o RLEList.o main.o -o AsciiArtTool

main.o:  RLEList.h AsciiArtTool.h main.c
	gcc -std=c99 -Wall -pedantic-errors -Werror -DNDEBUG -g -c main.c

RLEList.o: RLEList.c RLEList.h
	gcc -std=c99 -Wall -pedantic-errors -Werror -DNDEBUG -g -c RLEList.c 

AsciiArtTool.o: RLEList.h AsciiArtTool.c AsciiArtTool.h
	gcc -std=c99 -Wall -pedantic-errors -Werror -DNDEBUG -g -c AsciiArtTool.c


clean:
	rm -f RLEList.o AsciiArtTool.o main.o AsciiArtTool
