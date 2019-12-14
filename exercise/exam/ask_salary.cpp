#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int n, m, x;
    map<int, int> Count;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        Count[x]++;
    }
    while(m--) {
        cin >> x;
        cout << Count[x] << endl;
    }
    return 0;
}
