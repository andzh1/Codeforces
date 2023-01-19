#include <bits/stdc++.h>
using namespace std;


signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int64_t T;
    cin >> T;
    while (T--) {
        int64_t a, b, c;
        cin >> a >> b >> c;
        cout << c*b + a << ' ' << b << ' ' << a + c + c*b << '\n';

    }
}
