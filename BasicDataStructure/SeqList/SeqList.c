

void SeqListInit(SeqListType *SL)
{
    SL->ListLen = 0;
}
int SeqListLength(SeqListType *SL)
{
    return SL->ListLen;
}
int SeqListAdd(SeqListType *SL, DATA data)
{
    if(SL->ListLen >= MAXSIZE)
    {
        printf("The SeqList is full \n");
        return 0;
    }
    SL->ListLen ++;
    printf("\nxhl -- len:%d\n", SL->ListLen);
    SL->ListData[SL->ListLen] = data;
    return 1;
}

int SeqListInsert(SeqListType * SL, int n, DATA data)
{
    int i=0;
    if(SL->ListLen >= MAXSIZE)
    {
        printf("The SeqList is full \n");
        return 0;
    }
    if((n < 1) || (n > SL->ListLen-1))
    {
        printf("Wrong Location to insert\n");
        return 0;
    }
    for(i=SL->ListLen; i>=n;i--)
    {
        SL->ListData[i+1] = SL->ListData[i];
    }
    SL->ListData[n] = data;
    SL->ListLen ++;
    return 1;
}


int SeqListDelete(SeqListType * SL, int n)
{
    int i = 0;
    if((n < 1) || (n > SL->ListLen+1))
    {
        printf("Wrong Location to delete \n");
        return 0;
    }
    for(i=n; i<SL->ListLen;i++)
    {
        SL->ListData[i] = SL->ListData[i+1];
    }
    SL->ListLen --;
    return 1;
}


DATA * SeqListFindByNum(SeqListType *SL, int n)
{
    if((n < 1) || (n > SL->ListLen+1))
    {
        printf("Wrong Location to find \n");
        return NULL;
    }
    
    return &(SL->ListData[n]);
}

int SeqListFindByCont(SeqListType *SL, char *key)
{
    int i =0;
    for(i=1; i<=SL->ListLen; i++)
    {
        printf("\nlist:%s--input:%s\n", SL->ListData[i].key, key);
        if(strcmp(SL->ListData[i].key, key) == 0)
        {
            //at least 1
            return i;
        }
    }
    
    //0 mean an invalid index
    return 0;
}














