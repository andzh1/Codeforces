#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n, x, y;
        cin >> n >> y >> x;
        int a[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        int maxdif = 0;
        for(int i = 1; i < n; i++) {
            maxdif = max(maxdif, abs(a[i] - a[i-1]));
        }
        if(maxdif > 1) cout << "0\n";
        else if(maxdif == 1) cout << min(x, y) << '\n';
        else cout << min(x, y) + x << '\n';
    }
}