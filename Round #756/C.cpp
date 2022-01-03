#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        long long n;
        cin >> n;
        long long a [n];
        for (int i = 0; i < n; ++i) cin >> a[i];
        if (a[0] != n && a[n-1] != n) {
            cout << "-1\n";
            continue;
        }
        int left = 0, right = n - 1;
        if (a[0] == n) left++;
        if (a[n-1] == n) right--;
        for (int i = right; i >= left; --i) cout << a[i] << ' ';
        cout << n << '\n';
        }
}