#include <bits/stdc++.h>

using namespace std;
// #define int64_t int64_t64_t

signed main() {
    int64_t T;
    cin >> T;
    while(T--) {
        string s;
        cin >> s;
        int64_t max_cost;
        cin >> max_cost;
        vector<int64_t> amount_of_letters (27, 0);
        vector<vector<int64_t>> indexes (27, vector<int64_t>());
        int64_t total_cost = 0;
        for (int64_t i = 0; i < s.length(); ++i) {
            int cost = 1 + s[i] - 'a';
            ++amount_of_letters[cost];
            total_cost += (cost);
            indexes[cost].push_back(i);
        }
        if (total_cost <= max_cost) {
            cout << s;
            continue;
        }
        int64_t current_letter_cost = 26;
        while (total_cost > max_cost) {
            if (current_letter_cost == 0) {
                cout << "" << endl;
                break;
            }
            if (total_cost - current_letter_cost * amount_of_letters[current_letter_cost] > max_cost) {
                total_cost -= current_letter_cost * amount_of_letters[current_letter_cost];
                for (auto ind : indexes[current_letter_cost]) s[ind] = '1';
                --current_letter_cost;
                continue;
            }
            int64_t required_number = 0;
            while (total_cost - current_letter_cost * required_number > max_cost) {
                s[indexes[current_letter_cost][required_number]] = '1';
                ++required_number;
            }
            // for (int64_t i = 26; i > current_letter_cost; --i) {
            //     for (auto x : indexes[i]) s[x] = '1';
            // }
            // for (int64_t i = 0; i < required_number; ++i) {
            //     s[indexes[current_letter_cost][i]] = '1';
            // }
            break;
        }
        if (!current_letter_cost) continue;
        string ans = "";
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != '1') ans.push_back(s[i]);
        }
        cout << ans << endl;
    }
}