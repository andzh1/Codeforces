#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    bool a[n];
    int am = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = (x == 1);
        if(a[i]) am++;
    }
    for(int i = 0; i < q; i++) {
        int t, ip;
        cin >> t >> ip;
        if(t == 2) {
            if(ip > am) cout << "0\n";
            else cout << "1\n";
        }
        else {
            ip--;
            a[ip] = !a[ip];
            if(a[ip]) am++;
            else am--;
        }
    }
}