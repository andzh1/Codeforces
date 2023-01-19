#include <bits/stdc++.h>

using namespace std;
// #define long long long long;


signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    long long T;
    cin >> T;
    vector<bool> remain;

    while (T--) {
        long long n;
        cin >> n;
        long long numb_of_participants = (1 << n);
        remain.resize(numb_of_participants, true);
        for (int i = 0; i < numb_of_participants; ++i) remain[i] = true;
        long long cnt = numb_of_participants;
        vector<long long> to_change (4);
        for (long long i = 0; i < n && cnt > 1; ++i) {
            long long next = 0;
            for (long long j = 0; j < cnt / 4; ++j) {
                if (cnt == 2) break;
                to_change[0] = next;
                while (!remain[to_change[0]]) ++to_change[0];
                for (long long k = 1; k < 4; ++k) {
                    to_change[k] = to_change[k-1] + 1;
                    while (!remain[to_change[k]]) ++to_change[k];
                }
                next = to_change[3] + 1;
                cout << "? " << to_change[1] + 1 << ' ' << to_change[2] + 1 << endl;
                long long x;
                cin >> x;
                if (x == 0) {
                    remain[to_change[1]] = false;
                    remain[to_change[2]] = false;
                    cout << "? " << to_change[0] + 1 << ' ' << to_change[3] + 1 << endl;
                    long long y;
                    cin >> y;
                    if (y == 1) {
                        remain[to_change[3]] = false;
                    }
                    if (y == 2) {
                        remain[to_change[0]] = false;
                    }
                } else if (x == 1) {
                    remain[to_change[0]] = false;
                    remain[to_change[2]] = false;
                    cout << "? " << to_change[1] + 1 << ' ' << to_change[3] + 1 << endl;
                    long long y;
                    cin >> y;
                    if (y == 1) {
                        remain[to_change[3]] = false;
                    }
                    if (y == 2) {
                        remain[to_change[1]] = false;
                    }
                } else if (x == 2) {
                    remain[to_change[1]] = false;
                    remain[to_change[3]] = false;
                    cout << "? " << to_change[0] + 1 << ' ' << to_change[2] + 1 << endl;
                    long long y;
                    cin >> y;
                    if (y == 1) {
                        remain[to_change[2]] = false;
                    }
                    if (y == 2) {
                        remain[to_change[0]] = false;
                    }
                }
            }
            if (cnt == 2) {
                vector<long long> to_change2 (2);
                to_change2[0] = 0;
                while (to_change2[0] < numb_of_participants && !remain[to_change2[0]]) ++to_change2[0];
                to_change2[1] = to_change2[0] + 1;
                while (to_change2[1] < numb_of_participants && !remain[to_change2[1]]) ++to_change2[1];
                cout << "? " << to_change2[0] + 1 << ' ' << to_change2[1] + 1 << endl;
                long long c;
                cin >> c;
                if (c == 1) {
                    remain[to_change2[1]] = false;
                }
                if (c == 2) {
                    remain[to_change2[0]] = false;
                }
                break;
            }
            cnt /= 4;

        }
        for (long long j = 0; j < (numb_of_participants); ++j) {
            if (remain[j]) {
                cout << "! " << j+1 << endl;
                break;
            }
        }
    }
}