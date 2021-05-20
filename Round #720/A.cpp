#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        long long a, b;
        cin >> a >> b;
        if(b == 1) cout << "no\n";
        else {
            cout << "yes\n";
            cout << a*(2*b-1) << " " << a << " " << a*b*2 << '\n';
        }
    }
}