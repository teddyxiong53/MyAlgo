#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

/*
    至少要3个数才有意义吧。

*/
int judge_len(vector<int> a)
{
    int n = a.size();
    int len = 2;
    int max = len;
    for(int i=0; i<n-2; i++) {
        if(((unsigned long long)(a[i] + a[i+1]) <= a[i+2]) && (a[i] <= a[i+1]) &&(a[i+1] <= a[i+2]) ) {
            len += 1;
            //printf("[%d]:%d, [%d]:%d, [%d]:%d\n",i, a[i], i+1, a[i+1], i+2, a[i+2]);
        } else {
            if(len > max) {
                max = len;
            }
            len = 2;

        }
    }
    if(max >=3) {
        return max;
    }
    return 0;
}
int main()
{
    int groups;
    cin >> groups;
    // cout << "groups:" << groups << endl;
    vector<int> lens(groups);
    vector<vector<int>> arrays;
    int n;
    for(int i=0; i<groups; i++) {
        cin>> n;
        lens.push_back(n);
        vector<int> v(n);
        // cout << "n:" << n << endl;
        for(int j=0;j <n; j++) {
            cin >> v[j];
            // cout << v[j] << endl;
        }
        arrays.push_back(v);
    }
    for(auto arr: arrays) {
        int ret = judge_len(arr);
        cout << ret << endl;
    }
    // cout << "end" << endl;
    return 0;
}

