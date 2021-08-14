#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    int a[n], b[m];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    long long ia = 0, ib = 0;
    long long ans = 0;
    while(ia < n && ib < m) {
        if(a[ia] < b[ib]) ia++;
        else if(a[ia] > b[ib]) ib++;
        else {
            long long equa = 0, equb = 0;
            while(a[ia+equa] == a[ia] && (ia + equa) < n) equa++;
            while(b[ib+equb] == b[ib] && (ib + equb) < m) equb++;
            ans += equa*equb;
            ia += equa;
            ib += equb;
        }
    }
    
    cout << ans;
}