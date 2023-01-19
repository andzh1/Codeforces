#include <bits/stdc++.h>

using namespace std;

int get(int left, int right) {
    cout << "? 2 " << left + 1 << ' ' << right + 1 << endl;
    int diff;
    cin >> diff;
    return diff;
}

signed main() {
    int n;
    cin >> n;
    string s (n, ' ');
    vector<int> additions;
    int diff = 0;
    for (int i = 0; i < n; ++i) {
        cout << "? 2 1 " << ' ' << i + 1 << endl;
        int cur_dif;
        cin >> cur_dif;
        if (diff == cur_dif - 1) {
            diff = cur_dif;
            additions.push_back(i);
        }
        if (additions.size() == 26) break;
    }
    // if (additions.size() == 26);
    // cout << "? 1 1" << endl;
    // cin >> s[0];
    queue<int> lasts;
    int current_different = 0, left_edge = 0;
    for (int right_edge = 0; right_edge < n; ++right_edge) {
        int diff = get(left_edge, right_edge);
        if (diff == current_different) {
            while (left_edge != right_edge) {
                int diff_with = get(left_edge, right_edge);
                int diff_without = get(left_edge, right_edge - 1);
                if (diff_with == 1 + diff_without) {
                    s[right_edge] = s[left_edge - 1];
                    
                    break;
                }
                ++left_edge;
                current_different = diff_with;
            }
            if (left_edge == right_edge) s[right_edge] = s[left_edge - 1];
            continue;
        } else {
            if (get(0, right_edge) < 26) {
                cout << "? 1 " << right_edge + 1 << endl;
                cin >> s[right_edge];
            } else {

            }
        }
    }
}