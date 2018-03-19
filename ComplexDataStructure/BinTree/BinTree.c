#include <stdio.h>
#include <stdlib.h>

typedef char DATA;

typedef struct ChainTree
{
    DATA data;
    struct ChainTree *left;
    struct ChainTree *right;
} ChainBinTree;

ChainBinTree * BinTreeInit(ChainBinTree *node)
{
    if(node != NULL)
    {
        return node;
    }
    else
    {
        return NULL;
    }
}

/**
    bt: parent node
    node: child node
    n : 1; left, 2:right\
    return: 0 fail, 1: success
*/
int BinTreeAddNode(ChainBinTree * bt, ChainBinTree * node, int n)
{
    if(bt == NULL)
    {
        printf("parent node not exist \n");
        return 0;
    }
    if(n == 1)
    {
        if(bt->left)
        {
            printf("left is not empty \n");
            return 0;
        }
        bt->left = node;
    }
    else if(n == 2)
    {
        if(bt->right)
        {
            printf("right is not empty \n");
            return 0;
        }
        bt->right = node;
    }
    else
    {
        printf("n should be 1 or 2 \n");
        return 0;
    }
    return 1;
}


/**
    get the left tree of node.
    
*/
ChainBinTree * BinTreeLeft(ChainBinTree *bt)
{
    if(bt)
    {
        return bt->left;
    }
    return NULL;
}

/**
    get the right tree of node.
    
*/
ChainBinTree * BinTreeRight(ChainBinTree *bt)
{
    if(bt)
    {
        return bt->right;
    }
    return NULL;
}

int BinTreeIsEmpty(ChainBinTree * bt)
{
    if(bt)
    {
        return 0;   
    }
    else
    {
        return 1;
    }
}

int BinTreeDepth(ChainBinTree *bt)
{
    int dep1 = 0, dep2 = 0;
    if(bt == NULL)
    {
        return 0;
    }
    dep1 = BinTreeDepth(bt->left);
    dep2 = BinTreeDepth(bt->right);
    if(dep1>dep2)
    {
        return dep1+1;
    }
    else
    {
        return dep2+1;
    }
}


ChainBinTree * BinTreeFind(ChainBinTree* bt, DATA data)
{
    ChainBinTree *p = NULL;
    if(bt == NULL)
    {
        return NULL;
    }
    if(bt->data == data)
    {
        return bt;
    }
    else
    {
        if((p=BinTreeFind(bt->left, data)))
        {
            return p;
        }
        else if(p=BinTreeFind(bt->right, data))
        {
            return p;
        }
        else
        {
            return NULL;
             
        }
    }
}



void BinTreeClear(ChainBinTree *bt)
{
    if(bt)
    {
        BinTreeClear(bt->left);
        BinTreeClear(bt->right);
        free(bt);
        bt = NULL;
    }
}


void BinTree_DLR(ChainBinTree* bt, void (*oper)(ChainBinTree *p))
{
    if(bt)
    {
        oper(bt);
        BinTree_DLR(bt->left, oper);
        BinTree_DLR(bt->right, oper);
    }
}

void BinTree_LDR(ChainBinTree* bt, void (*oper)(ChainBinTree *p))
{
    if(bt)
    {
        BinTree_LDR(bt->left, oper);
        oper(bt);
        BinTree_LDR(bt->right, oper);
    }
}
    

void BinTree_LRD(ChainBinTree* bt, void (*oper)(ChainBinTree *p))
{
    if(bt)
    {
        BinTree_LRD(bt->left, oper);
        BinTree_LRD(bt->right, oper);
        oper(bt);
    }
}
   
       
/**
   traverse by level.
   
*/


