
SeqQueue * SeqQueueInit()
{
    SeqQueue *q ;
    q = (SeqQueue *)malloc(sizeof(SeqQueue));
    if(q == NULL)
    {
        printf("SeqQueueInit failed \n");
        return NULL;   
    }
    q->head = 0;
    q->tail = 0;
    return q;
}

void SeqQueueFree(SeqQueue *q)
{
    if(q!=NULL)
    {
        free(q);
    }
}

int SeqQueueIsEmpty(SeqQueue *q)
{
    return (q->head == q->tail);
}

int SeqQueueIsFull(SeqQueue *q)
{
    return (QUEUEMAX == q->tail);
}

int SeqQueueLen(SeqQueue *q)
{
    return (q->tail - q->head);
}


int SeqQueueIn(SeqQueue *q, DATA data)
{
    if(SeqQueueIsFull(q))
    {
        printf("SeqQueue is full \n");
        return 0;    
    }
    q->data[q->tail++] = data;
    return 1;
}

DATA *SeqQueueOut(SeqQueue *q)
{
    if(SeqQueueIsEmpty(q))
    {
        printf("SeqQueue is empty \n");
        return NULL;
    }
    return &(q->data[q->head++]);
}



