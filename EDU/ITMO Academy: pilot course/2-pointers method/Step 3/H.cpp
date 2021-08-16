#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, s, wA, wB;
    cin >> n >> m >> s >> wA >> wB;
    long long a[n];
    long long b[m];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    sort(a, a+n);
    sort(b, b+m);
    long long cursum = 0;
    long long maxSum = cursum, curWeight = 0;
    long long c[n+m];
    for(int i = 0; i < n; i++) c[i] = a[i];
    for(int i = 0; i < m; i++) c[i+n] = b[m-1-i];
    long long l = 0;
    for(int r = 0; r < n+m; r++) {
        cursum += c[r];
        curWeight += ((r >= n)? wB : wA);
        while(curWeight > s) {
            curWeight -= (l < n)? wA: wB; 
            cursum -= c[l];
            l++;
        }
        if(curWeight <= s) maxSum = max(maxSum, cursum);
    }
    cout << maxSum;
}