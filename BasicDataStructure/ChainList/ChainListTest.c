#include <stdio.h>

typedef struct 
{
    char key[15];
    char name[20];
    int age;
} DATA;

#include "ChainList.h"
#include "ChainList.c"

void ChainListAll(ChainListType * head)
{
    ChainListType *node;
    DATA data;
    node = head;
    while(node)
    {
        data = node->data;
        printf("(%s, %s, %d) \n", data.key, data.name, data.age);
        node = node->next;
    }
    
}

int main()
{
    printf("-----------------ChainList Test------------ \n");
    return 0;
}





