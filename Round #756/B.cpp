#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        long long a, b;
        cin >> a >> b;
        long long sum = (a + b) / 4;
        cout << min(sum, min(a, b));
        cout << '\n';
    }
}