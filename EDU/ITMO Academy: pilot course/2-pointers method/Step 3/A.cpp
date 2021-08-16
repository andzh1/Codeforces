#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, p;
    cin >> n >> p;
    long long a[n];
    long long l = 0, length = 0, start, sum = 0, songsNumber = 0;
    for(long long i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    songsNumber += n*(p/sum);
    p %= sum;
    if(p == 0) cout << "1 " << songsNumber;
    else {
        long long b[2*n];
        for(long long i = 0; i < 2*n; i++) b[i] = a[i%n];
        sum = 0;
        long long res = INT64_MAX;
        for(long long r = 0; r < 2*n; r++) {
            sum += b[r];
            while(sum - b[l] >= p) {
                sum -= b[l];
                l++;
            }
            if(sum >= p) {
                if(res > r-l+1) {
                    res = r-l+1;
                    start = l;
                }
            }
        }
        cout << start+1 << " " << songsNumber+res;
    }
}