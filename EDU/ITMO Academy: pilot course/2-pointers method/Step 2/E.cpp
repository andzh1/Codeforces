#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    long long a[n];
    for(long long i = 0; i < n; i++) cin >> a[i];
    long long l = 0, res = 0;
    map <int, int> difnumbs;
    for(int i = 0; i < n; i++) difnumbs[a[i]] = 0;
    long long curnum = 0;
    for(int r = 0; r < n; r++) {
        difnumbs[a[r]]++;
        if(difnumbs[a[r]] == 1) curnum ++;
        while(curnum > k) {
            difnumbs[a[l]]--;
            if(difnumbs[a[l]] == 0) curnum --;
            l++;
        }
        res += r-l+1;
    }
    cout << res;
}