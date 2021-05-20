#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int count0 = 0;
        for(int i = 0; i < n; i++) {
            count0 += s[i] == '0';
        }
        if(count0 == 0) cout << "DRAW\n";
        else {
            if(count0 % 2 == 0 || count0 == 1) cout << "BOB\n";
            else cout << "ALICE\n";
        }
    }
}