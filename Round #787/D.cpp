#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int TESTS;
    std::cin >> TESTS;
    while(TESTS--) {
        int n;
        std::cin >> n;
        vector<int> parents (n);
        set<int> leaves;
        for (int i = 0; i < n; ++i) {
            leaves.insert(i);
        }
        for (int i = 0; i < n; ++i) {
            cin >> parents[i];
            --parents[i];
            leaves.erase(parents[i]);
        }
        if (n == 1) {
            cout << "1\n";
            cout << "1\n";
            cout << "1\n";
            continue;
        }
        cout << leaves.size() << '\n';
        vector<bool> visited (n, false);
        while (!leaves.empty()) {
            int current_leave = *leaves.begin();
            leaves.erase(current_leave);
            vector<int> current_path;
            while (!visited[current_leave]) {
                visited[current_leave] = true;
                current_path.push_back(current_leave);
                current_leave = parents[current_leave];
            }
            cout << current_path.size() << '\n';
            for (int i = current_path.size() - 1; i >= 0; --i) cout << current_path[i] + 1 << ' ';
            cout << '\n';
        }
    }
}