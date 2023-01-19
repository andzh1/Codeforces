#include <bits/stdc++.h>

using namespace std;
#define int64_t int;

signed main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> distances (3);
        int sum = 0;
        for (int& d : distances) {
            cin >> d;
            sum += d;
        }
        if (sum % 2) {
            cout << "NO\n";
            continue;
        }
        sum /= 2;
        if (sum > n-1) {
            cout << "NO\n";
            continue;
        }
        vector<int> new_distances(3);
        new_distances[0] = sum - distances[1];
        new_distances[1] = sum - distances[2];
        new_distances[2] = sum - distances[0];
        bool ans = true;
        for (int i = 0; i < 3; ++i) {
            if (new_distances[i] < 0) {
                ans = false;
                break;
            }
        }
        if (!ans) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        int middle = n - 1;
        for (int i = 0; i < 3; ++i) {
            if (new_distances[i] == 0) {
                middle = i;
            }
        }
        // if (middle == n) {
        int last = 4;
        int edges = 0;
        for (int i = 0; i < 3; ++i) {
            if (new_distances[i] == 1) {
                cout << middle+1 << ' ' << i+1 << '\n';
                ++edges;
                continue;
            }
            if (new_distances[i] > 1) {
                cout << middle+1 << ' ' << last << '\n';
                ++edges;
                ++last;
                --new_distances[i];
                while (new_distances[i] > 1) {
                    cout << last - 1 << ' ' << last << '\n';
                    ++edges;
                    ++last;
                    --new_distances[i];
                }
                cout << last-1 << ' ' << i + 1 << '\n';
                ++edges;
                // ++last;
            }
        }
        int leaf = middle + 1;
        // if (middle == leaf) leaf = 2;
        if (edges >= n - 1) continue; 
        cout << leaf << ' ' << last << '\n';
        ++edges;
        ++last;
        while (edges < n - 1) {
            cout << last - 1 << ' ' << last << '\n';
            ++last;
            ++edges;
        }
    }
}