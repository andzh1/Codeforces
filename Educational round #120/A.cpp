#include <bits/stdc++.h>

using namespace std;

int main() {
    long long T;
    cin >> T;
    while (T--) {
        long long a[3];
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a + 3);
        if (a[2] == a[1] + a[0]) cout << "yes\n";
        else if (a[1] == a[0] && a[2] % 2 == 0) cout << "yes\n";
        else if (a[2] == a[1] && a[0] % 2 == 0) cout << "yes\n";
        else cout << "no\n";
    }
}