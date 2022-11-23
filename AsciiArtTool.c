#include "AsciiArtTool.h"

RLEList asciiArtRead(FILE* in_stream)
{
    char value;
    RLEList header=RLEListCreate();
    if(!header)
        return NULL;
    while(fscanf(in_stream,"%c",&value)!=EOF)
        RLEListAppend(header,value);
    return header;  
}

RLEListResult asciiArtPrint(RLEList list, FILE *out_stream)
{
    if(!list)
        return RLE_LIST_NULL_ARGUMENT;
    int size= RLEListSize(list);
    RLEListResult result= RLE_LIST_SUCCESS;
    for(int i=0;i<size&&result==RLE_LIST_SUCCESS;i++)
        fprintf(out_stream,"%c",RLEListGet(list,i,&result));
    if(result!=RLE_LIST_SUCCESS)
        return RLE_LIST_NULL_ARGUMENT;
    return RLE_LIST_SUCCESS;
}

RLEListResult asciiArtPrintEncoded(RLEList list, FILE *out_stream)
{
    if(!list)
        return RLE_LIST_NULL_ARGUMENT;
    RLEListResult result = RLE_LIST_SUCCESS;
    char*str= RLEListExportToString(list,&result);
    if(result!=RLE_LIST_SUCCESS)
        return RLE_LIST_NULL_ARGUMENT;
    fprintf(out_stream,"%s",str);
    free(str);
    return RLE_LIST_SUCCESS;
}

char invert(char val)
{
    if(val==' ')
        return '@';
    else if(val=='@')
        return ' ';
    else
        return val;
}
