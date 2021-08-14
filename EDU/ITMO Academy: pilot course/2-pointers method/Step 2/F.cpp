#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    long long a[n];
    for(long long i = 0; i < n; i++) cin >> a[i];
    long long l = 0, res = 0;
    multiset <long long> curseg;
    for(long long r = 0; r < n; r++) {
        curseg.insert(a[r]);
        while(*curseg.rbegin() - *curseg.begin() > k) {
            curseg.erase(curseg.find(a[l]));
            l++;
        }
        res += r-l+1;
    }
    cout << res;
}