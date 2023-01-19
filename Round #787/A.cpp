#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int TESTS;
    std::cin >> TESTS;
    while(TESTS--) {
        int a, b, c, x, y;
        std::cin >> a >> b >> c >> x >> y;
        bool ans = (c - (max(x - a, 0) + max(0, y - b))) >= 0;
        (ans)? std::cout << "YES\n" : std::cout << "NO\n";
    }
}