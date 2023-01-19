#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int TESTS;
    std::cin >> TESTS;
    while(TESTS--) {
        int n;
        std::cin >> n;
        vector<int> input (n);
        for (int i = 0; i < n; ++i) {
            cin >> input[i];
        }
        int ans = 0;
        for (int i = n - 2; i >= 0; --i) {
            while (input[i] >= input[i + 1] && input[i]) {
                input[i] /= 2;
                ++ans;
            }
            if (input[i] == 0 && input[i + 1] == 0) {
                ans = -1;
                break;
            }
        }
        cout << ans << '\n';
    }
}