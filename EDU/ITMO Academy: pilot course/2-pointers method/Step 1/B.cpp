#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    int ia = 0;
    int ips[m];
    for(int ib = 0; ib < m; ib++) {
        while(a[ia] < b[ib] && ia < n) ia++;
        ips[ib] = ia;
    }
    for(int i = 0; i < m; i++) cout << ips[i] << " ";

}