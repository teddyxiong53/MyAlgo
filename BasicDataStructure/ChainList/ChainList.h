#ifndef __CHAIN_LIST_H__
#define __CHAIN_LIST_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
    DATA data;
    struct node *next;
} ChainListType;
//add 
ChainListType * ChainListAddFirst(ChainListType *head, DATA data);

ChainListType * ChainListAddEnd(ChainListType *head, DATA data);

ChainListType * ChainListInsert(ChainListType * head, char *findkey, DATA data);

//del
int ChainListDelete(ChainListType* head, char *key);

//query
ChainListType * ChainListFind(ChainListType *head, char *key);

int ChainListLength(ChainListType *head);



#endif
