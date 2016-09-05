#include <stdio.h>

typedef struct 
{
    char key[15];
    char name[20];
    int age;
} DATA;

#include "SeqList.h"
#include "SeqList.c"

int SeqListAll(SeqListType *SL)
{
    int i=0;
    for(i=1;i<=SL->ListLen;i++)
    {
        printf("\n(%s,%s,%d) \n", SL->ListData[i].key,SL->ListData[i].name, SL->ListData[i].age);
    }
    return 0;
}


int main()
{
    int i;
    SeqListType SL;
    DATA data, *data1;
    char key[15];
    //init SeqList
    SeqListInit(&SL);
    do
    {
        printf("please input No Name Age :");
        fflush(stdin);
        scanf("%s%s%d", &data.key, &data.name, &data.age);
        if(data.age != 0)
        {
            if(!SeqListAdd(&SL, data))
            {
                break;
            }
        }
        else
        {
            
            break;
        }
    }while(1);
    printf("\n------Content In the SeqList---------\n");
    SeqListAll(&SL);
    fflush(stdin);

    printf("\n-------Test get by num- ------\n");
    printf("please input a num:\n");
    scanf("%d",&i);
    data1 = SeqListFindByNum(&SL, i);
    if(data1)
    {
        printf("\n%d content is(%s %s %d)\n", i ,data1->key, data1->name, data1->age);
    }
    else
    {
        printf("\n%d not found\n");
    }
    fflush(stdin);

    printf("\n-------Test get by content- ------\n");
    scanf("%s",key);
    i = SeqListFindByCont(&SL, key);
    if(i)
    {
        printf("\n%s content is(%s %s %d)\n",key,  SL.ListData[i].key, SL.ListData[i].name, SL.ListData[i].age);
    }
    else
    {
        printf("\n%s not found\n", key);
    }
    fflush(stdin);
    getchar();
    return 0;
}
