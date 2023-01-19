#include <bits/stdc++.h>
using namespace std;


int main() {
    long long T;
    cin >> T;
    while (T--) {
        long long n;
        cin >> n;
        long long a[n];
        map<long long, vector<long long>> positionsOf;
        for (long long i = 0; i < n; ++i) {
            cin >> a[i];
            positionsOf[a[i]].push_back(i);
        }

        long long answer = -1;
        for (auto x: positionsOf) {
            if (x.second.size() > 1) {
                for (int i = 1; i < x.second.size(); ++i) {
                    answer = max(answer, n - (x.second[i] - x.second[i-1]));
                }
            }
        }
        cout << answer << '\n';
    }
}