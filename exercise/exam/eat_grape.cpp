#include <iostream>
#include <cmath>
using namespace std;
void sort(long list[], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (list[i] > list[j])
                swap(list[i], list[j]);
}

int main()
{
    int n;
    long l[3], sum;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> l[0] >> l[1] >> l[2];
        sort(l, 3);
        sum = l[0] + l[1] + l[2];
        cout << max((sum + 2) / 3, (l[0] + 1) / 2) << endl;
    }
}
