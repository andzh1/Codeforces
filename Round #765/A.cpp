#include <bits/stdc++.h>
using namespace std;

#define intf int_fast64_t

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, l;
        cin >> n >> l;
        int input[n];
        for (int i = 0; i < n; ++i) {
            cin >> input[i];
        }
        int answer = 0;
        for (int curPowOf2 = 0; curPowOf2 < l; curPowOf2++) {
            int x = 0;
            for (int i = 0; i < n; ++i) {
                x += input[i] % 2;
                input[i] /= 2;
            }
            if (x > n/2) {
                answer += (1<<curPowOf2);
            }
        }
        cout << answer << '\n';
    }
}