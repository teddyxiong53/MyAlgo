
#include <stdio.h>
#define NUM 5
int data[5] = {3,2,1,4,5};

int Division(int a[], int left, int right)
{
    int base = a[left];
    while(left<right)
    {
        while((left<right)
                && (a[right]>base))
        {
            right --;
        }
        a[left] = a[right];
        while((left<right)
                && (a[left]<base))
        {
            left++;
        }
        a[right] = a[left];
    }
    a[left] = base;
    return left;
}

void QuickSort(int a[], int left, int right)
{
    int i,j;
    if(left < right)
    {
        i = Division(a, left, right);
        QuickSort(a, left, i-1);
        QuickSort(a, i+1, right);
    }
}



int main()
{
    QuickSort(data, 0, NUM-1);
    int i = 0;
    printf("\n-----------QuickSort-------------\n");
    for(i=0; i<NUM; i++)
    {
        printf("%d ", data[i]);
    }
    
    
    return 0;
}















