#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        string n;
        cin >> n;
        if((n[n.size() - 1] - '0') % 2 == 0) {
            cout << "0\n";
            continue;
        }
        if((n[0] - '0') % 2 == 0) {
            cout << "1\n";
            continue;
        }
        bool possible = false;
        for (int i = 0; i < n.size(); ++i) {
            if ((n[i] - '0') % 2 == 0) possible = true;
        }
        if (possible) {
            cout << "2\n";
            continue;
        }
        cout << "-1\n";
    }
}