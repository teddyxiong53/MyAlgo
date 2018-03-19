
#include <stdio.h>
#define NUM 5
int data[5] = {3,2,1,4,5};

void BubbleSort(int a[], int n)
{
    int i,j,t;
    printf("\n----------BubbleSort-------- \n");
    for(i=0; i<n; i++)
    {
        for(j=n-1; j>i; j--)
        {
            if(a[j-1] > a[j])
            {
                t = a[j-1];
                a[j-1] = a[j];
                a[j] = t;
            }
        }
        printf("\nthe %02d time result: \n", i+1);
        for(j=0; j<n; j++)
        {
            printf("%d ", a[j]);
        }
    }
}


/**
    improved bubble sort .
    if in one time compare, no data was changed ,
    it means all data has been sort, no need to compare anymore.
*/
void BubbleSort1(int a[], int n)
{
    int i,j,t;
    int flag = 0;
    printf("\n----------BubbleSort1-------- \n");
    for(i=0; i<n; i++)
    {
        for(j=n-1; j>i; j--)
        {
            if(a[j-1] > a[j])
            {
                t = a[j-1];
                a[j-1] = a[j];
                a[j] = t;
                flag = 1;
            }
        }
        printf("\nthe %02d time result: \n", i+1);
        for(j=0; j<n; j++)
        {
            printf("%d ", a[j]);
        }
        if(flag == 0)
        {
            break;
        }
        else
        {
            flag = 0;
        }
    }
}

int main()
{
    BubbleSort(data, NUM);
    BubbleSort1(data, NUM);
    return 0;
}















