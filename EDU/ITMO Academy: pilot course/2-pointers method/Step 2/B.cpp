#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, s;
    cin >> n >> s;
    long long a[n];
    for(long long i = 0; i < n; i++) cin >> a[i];
    long long r = 0, res = n+1;
    long long sum = 0;
    for(int l = 0; l < n; l++) {
        while(sum < s && r < n) {
            sum += a[r];
            r++;
        }
        if(r <= n && sum >= s) res = min(res, r-l);
        else break;
        sum -= a[l];
    }
    if(res == n + 1) res = -1;
    cout << res;
}