#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        int k = 0;
        while(n > 0) {
            n /= 2;
            k++;
        }
        cout << (1<<(k-1)) - 1 << '\n';
    }
}