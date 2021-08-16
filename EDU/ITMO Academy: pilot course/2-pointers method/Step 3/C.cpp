#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, rad;
    cin >> n >> rad;
    long long d[n];
    for(int i = 0; i < n; i++) cin >> d[i];
    long long l = 0, ans = 0, right = 0;
    for(int r = 0; r < n; r++) {
        right = d[r];
        while(right - d[l+1] > rad && l < n-1) {
            l++;
        }
        if(right - d[l] > rad) ans += l+1;
    }
    cout << ans;
}