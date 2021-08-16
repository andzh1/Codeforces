#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, c;
    cin >> n >> c;
    string s;
    cin >> s;
    long long a[n];
    long long b[n];
    (s[0] == 'a')? a[0] = 1 : a[0] = 0;
    for(int i = 1; i < n; i++) {
        a[i] = a[i-1];
        if(s[i] == 'a') a[i]++;
    }
    long long l = 0, maxLength = 0, amountA = 0, amountB = 0, cur = 0;
    for(long long r = 0; r < n; r++) {
        if(s[r] == 'a') amountA++;
        if(s[r] == 'b') {cur += amountA; amountB ++;}
        while(c < cur) {
            if(s[l] == 'a') {amountA--; cur -= amountB;}
            if(s[l] == 'b') amountB--;
            l++;
        }
        if(c >= cur) maxLength = max(maxLength, r-l+1);
    }
    cout << maxLength;
}