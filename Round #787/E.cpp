#include <bits/stdc++.h>
using namespace std;


int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int TESTS;
    std::cin >> TESTS;
    while(TESTS--) {
        int n, number_of_operations;
        cin >> n >> number_of_operations;
        string s;
        cin >> s;
        if (number_of_operations >= 25) {
            cout << string(n, 'a') << '\n';
            continue;
        }
        char min_char = max('a', (char)(s[0] - number_of_operations));
        int index_of_first_not_a = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] - min_char > number_of_operations) {
                index_of_first_not_a = i;
                break;
            }
        }
        
        if (index_of_first_not_a == -1) {
            string answer;
            for (int i = 0; i < n; ++i) {
                answer.push_back(min(min_char, s[i]));
            }
            cout << answer << '\n';
            continue;
        }
        char max_char_before_not_a = min_char;
        for (int i = 0; i < index_of_first_not_a; ++i) {
            max_char_before_not_a = max(max_char_before_not_a, s[i]);
        }
        number_of_operations -= (max_char_before_not_a - min_char);
        // bool can_decrease = true;
        // if (index_of_first_not_a == 0) {
        //     can_decrease = 0;
        // }
        string answer;
        for (int i = 0; i < index_of_first_not_a; ++i) {
            answer.push_back(min(s[i], min_char));
        }
        for (int i = index_of_first_not_a; i < n; ++i) {
            if (s[i] <= max_char_before_not_a) {
                answer.push_back(min(s[i], min_char));
                continue;
            } 
            if (s[i] > s[index_of_first_not_a]) {
                answer.push_back(s[i]);
                continue;
            }
            char ch = s[i];
            // if (!can_decrease) {
            //     answer.push_back(ch);
            //     continue;
            // }
            char x = s[index_of_first_not_a] - number_of_operations;
            answer.push_back(min(ch, x));
        }
        cout << answer << '\n';
    }
}