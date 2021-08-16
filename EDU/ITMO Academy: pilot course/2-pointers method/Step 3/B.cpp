#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, s;
    cin >> n >> s;
    long long a[n];
    long long l = 0, res = 0;
    for(long long i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long sum = 0;
    for(int r = 0; r < n; r++) {
        sum += a[r];
        while(sum > s) {
            sum -= a[l];
            l++;
        }
        if(sum <= s) {
            long long length = r-l+1;
            res += length*(length+1)/2;
        }
    }
    cout << res;
}