#include "AsciiArtTool.h"


RLEList asciiArtRead(FILE* in_stream)
{
    if (!in_stream)
        return NULL;
    fopen(in_stream,"r");
    char value;
    RLEList hader=RLEListCreate();
    if(!header)
    {
        fclose(in_stream);
        return NULL;
    }

    while(fscanf(in_stream,"%c",&value)!=EOF)
        RLEListAppend(header,value);
    fclose(in_stream);
    return header;  
}

RLEListResult asciiArtPrint(RLEList list, FILE *out_stream)
{
    if(!out_stream||!list)
        return RLE_LIST_NULL_ARGUMENT;
    fopen(out_stream,"w");
    while(list->next)
    {
        for(int i=0;i<(list->size);i++)
            fprintf(out_stream,"%c",list->letter)
        list=list->next;
    }
    fclose(out_stream);
    return RLE_LIST_SUCCESS;
}

RLEListResult asciiArtPrintEncoded(RLEList list, FILE *out_stream)
{
    if(!out_stream||!list)
        return RLE_LIST_NULL_ARGUMENT;
    RLEListResult result = RLE_LIST_SUCCESS;
    char*str= RLEListExportToString(list,&result);
    if(result!=RLE_LIST_SUCCESS)
        return RLE_LIST_NULL_ARGUMENT;
    fopen(out_stream,"w");
    while(str)
    {
        fprintf(out_stream,"%c",*str);
        str++;
    }
    free(str);
    fclose(out_stream);
    return RLE_LIST_SUCCESS;
}