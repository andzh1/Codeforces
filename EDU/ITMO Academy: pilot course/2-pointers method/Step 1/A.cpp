#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    int ia = 0, ib = 0;
    int c[n+m];
    while(ia < n && ib < m) {
        if(a[ia] < b[ib]) {
            c[ia + ib] = a[ia];
            ia++;
        } else {
            c[ia + ib] = b[ib];
            ib++;
        }
    }
    if(ia < n) 
        for(int i = ia; i < n; i++) c[i + ib] = a[i];
    else 
        for(int i = ib; i < m; i++) c[i + ia] = b[i];
    for(int i = 0; i < n+m; i++) cout << c[i] << " ";

}