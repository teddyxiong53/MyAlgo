

ChainListType* ChainListAddEnd(ChainListType *head, DATA data)
{
    ChainListType *node, *h;
    node = (ChainListType *)malloc(sizeof(ChainListType));
    if(node == NULL)
    {
        printf("%s malloc failed \n", __FUNCTION__);
        return NULL;
    }
    node->data = data;
    node->next = NULL;
    if(head == NULL)
    {
        head = node;
        return head;
    }
    h = head;
    while(h->next != NULL)
    {
        h = h->next;
    }
    h->next = node;
    return head;
}


ChainListType* ChainListAddFirst(ChainListType *head, DATA data)
{
    ChainListType *node, *h;
    node = (ChainListType *)malloc(sizeof(ChainListType));
    if(node == NULL)
    {
        printf("%s malloc failed \n", __FUNCTION__);
        return NULL;
    }
    node->data = data;
    node->next = head;
    head = node;
    return head;
}

ChainListType * ChainListFind(ChainListType * head, char *findkey)
{
    ChainListType *node;
    node = head;
    while(node != NULL)
    {
        if(strcmp(node->data.key, findkey) == 0)
        {
            return node;
            
        }
        node = node->next;
    }
    printf("ChainListFind find nothing \n");
    return NULL;
}

ChainListType * ChainListInsert(ChainListType * head, char *findkey, DATA data)
{
    ChainListType *node, *node1;
    node = (ChainListType *)malloc(sizeof(ChainListType));
    if(node == NULL)
    {
        printf("%s malloc failed \n", __FUNCTION__);
        return NULL;
    }
    node->data = data;
    node1 = ChainListFind(head, findkey);
    if(node1 != NULL)
    {
        node->next = node1->next;
        node1->next = node;
    }
    else
    {
        free(node);
        printf("ChainListInsert failed \n");
    }
    return head;
}



int ChainListDelete(ChainListType * head, char *key)
{
    ChainListType *node, *node1;
    if(head == NULL )
    {
        return 0;
    }
    node1 = node = head;
    while(node != NULL)
    {
        if(strcmp(node->data.key, key) == 0)
        {
            node1->next = node->next;
            free(node);
            return 1;
        }
        else
        {
            node1 = node;
            node = node->next;
        }
        node = node->next;
    }
    return 0;
}



int ChainListLength(ChainListType *head)
{
    ChainListType *node;
    int i = 0;
    node = head;
    while(node != NULL)
    {
        node = node->next;
        i++;
    }
    return i;
}














