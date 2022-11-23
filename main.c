#include <stdio.h>
#include <string.h>
#include "AsciiArtTool.h"


int main(int argc, char** argv)
{
    if(argc!=4)
        return 0;
    FILE* input = fopen(argv[2],"r");
    if(!input)
        return 0;
    FILE* output = fopen(argv[3],"w");
    if(!output)
    {
        fclose(input);
        return 0;
    }

    RLEList list = asciiArtRead(input);

    if(!(strcmp(argv[1],"-e")))
        asciiArtPrintEncoded(list,output);
    else if(!(strcmp(argv[1],"-i")))
    {
        RLEListMap(list,invert);
        asciiArtPrint(list,output);
    }
    RLEListDestroy(list);
    fclose(input);
    fclose(output);
    return 0;
}