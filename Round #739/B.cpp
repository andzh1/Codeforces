#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int a,b,c;
        cin >> a >> b >> c;
        int maxim = abs(a-b)*2;
        if(c > maxim || a > maxim || b > maxim) cout << "-1" << endl;
        else {
            if(c > maxim/2) cout << c - maxim/2 << endl;
            else cout << c + maxim/2 << endl;
        }
    }
}