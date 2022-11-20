#include "RLEList.h"

RLEList last(RLEList list);



struct RLEList_t
{
    char letter;
    int size;
    struct RLEList_t* next;
};



//implement the functions here

RLEList RLEListCreate()
{
    RLEList first= malloc(sizeof(*first));
    if(!first)
        return NULL;
    first->letter=0;
    first->size=0;
    first->next=NULL;
    return first;
}


void RLEListDestroy(RLEList list)
{
    while(list)
    {
        RLEList toDelete=list;
        list=list->next;
        free(toDelete);
    }
}

RLEList last(RLEList list)
{
    if(!list)
        return NULL;
    
    while(list->next)
    {
        list=list->next;
    }
    return list;

}
RLEListResult RLEListAppend(RLEList list, char value)
{
    if(list==NULL)
        return RLE_LIST_NULL_ARGUMENT;
    RLEList l = last(list);
    if(l->size==0||l->letter!=value)
    {
        RLEList new_Node = malloc(sizeof(*new_Node));
        if(!new_Node)
            return RLE_LIST_NULL_ARGUMENT;
        new_Node->size=1;
        new_Node->letter=value;
        new_Node->next=l->next;
        l->next=new_Node;
    }
    else if(l->letter==value)
        (l->size)++;
    return RLE_LIST_SUCCESS;
        
        
    
}

int RLEListSize(RLEList list)
{
    if(!list)
        return -1;
    int sum=0;
    while(list)
    {
        sum+=list->size;
        list=list->next;
    }
    return sum;
}

RLEListResult RLEListRemove(RLEList list, int index)
{
    if(!list)
        return RLE_LIST_NULL_ARGUMENT;
    if(index<0||index>=RLEListSize(list))
        return RLE_LIST_INDEX_OUT_OF_BOUNDS;
    int curr_index=-1;
    RLEList temp = list, prev=list;
    while((curr_index+temp->size)<index)
    {
        prev=temp;
        curr_index+=temp->size;
        temp=temp->next;
    }
    if((temp->size)>1)
        (temp->size)--;
    else
    {
        prev->next=temp->next;
        free(temp);
    }

    return RLE_LIST_SUCCESS;
    
}

char RLEListGet(RLEList list, int index, RLEListResult *result)
{
    char value=0;
    if(!list)
    {
        if(result!=NULL)
            *result = RLE_LIST_NULL_ARGUMENT;
    }
    else if(index < 0 || index >= RLEListSize(list))
    {
        if(result!=NULL)
            *result = RLE_LIST_INDEX_OUT_OF_BOUNDS;
    }
        
    else
    {
        if(result!=NULL)
            *result = RLE_LIST_SUCCESS;
        int curr_index = -1;
        RLEList temp = list;
        while((curr_index + temp->size) < index)
        {
            curr_index += temp->size;
            temp = temp->next;
        }
        value=temp->letter;
    } 
    return value;
        
}

RLEListResult RLEListMap(RLEList list, MapFunction map_function)
{
    if(!list)
        return RLE_LIST_NULL_ARGUMENT;
    RLEList temp=list;
    while(temp->next)
    {
        temp->letter=map_function(temp->letter);
        temp=temp->next;
    }
    return RLE_LIST_SUCCESS;
}

char* RLEListExportToString(RLEList list, RLEListResult* result)
{
    if(!list)
    {
        *result=RLE_LIST_NULL_ARGUMENT;
        return NULL;
    }
    else
    {
        int count=0;
        RLEList temp=list;
        while(temp->next)
        {
            count++;
            temp=temp->next;
        }
        char* str=malloc((3*count+1)*sizeof(char));//needs to be free!!!
        if(!str)
        {
            *result=RLE_LIST_NULL_ARGUMENT;
            return NULL;
        } 
        else
        {
            *result=RLE_LIST_SUCCESS;
            RLEList temp2=list;
            str[3*count]=0;
            int index=0;
            while(temp2->next)
            {
                str[index]=temp2->letter;
                str[index+1]=temp2->size;
                str[index+2]='\n';
                temp2=temp2->next;
                index+=3;
            }
            return str;
        }
    }
}
