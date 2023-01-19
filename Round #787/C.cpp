#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int TESTS;
    std::cin >> TESTS;
    while(TESTS--) {
        // int n;
        // std::cin >> n;
        string input;
        cin >> input;
        int n = input.size();
        if (n == 1) {
            cout << "1\n";
            continue;
        }
        int first_zero = n - 1;
        for (int i = 0; i < n; ++i) {
            if (input[i] == '0') {
                first_zero = i;
                break;
            }
        }
        int last_1 = 0;
        for (int i = 0; i <= first_zero; ++i) {
            if (input[i] == '1') {
                last_1 = i;
            }
        }
        cout << (first_zero - last_1 + 1) << '\n';
    }
}