#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    int ans[10000];
    int ip = 0;
    for(int i = 1; i < 10000; i++) {
        if(i % 3 == 0 || i % 10 == 3) continue;
        else {
            ans[ip] = i;
            ip++;
        }
    }
    while(t--) {
        int k;
        cin >> k;
        cout << ans[k-1] << endl;
    }
}