#include <bits/stdc++.h>

using namespace std;
#define int64_t int;

signed main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> numbers (n);
        bool has_odd = false, has0 = false, has_non0 = false;
        for (int& in : numbers) {
            cin >> in;
            if (in % 2) {
                in += in % 10;
                has_odd = true;
            }
            if (in % 10 == 0) {
                has0 = true;
            } else {
                has_non0 = true;
            }
        }
        if (has0 && has_non0) {
            cout << "No\n";
            continue;
        }
        if (has0 && !has_non0) {
            bool ans = true;
            for (int i = 1; i < n; ++i) {
                if (numbers[i] != numbers[i-1]) {
                    ans = false;
                    break; 
                }
            }
            cout << ((ans)? "yes\n" : "no\n");
            continue;
        }
        for (int& in : numbers) {
            while (in % 10 != 2) {
                in += in % 10;
            }
        }
        bool ans = true;
        for (int i = 1; i < n; ++i) {
            if (abs(numbers[i] - numbers[i-1]) % 20) {
                ans = false;
                break; 
            }
        }
        cout << ((ans)? "yes\n" : "no\n");
    }
    

}