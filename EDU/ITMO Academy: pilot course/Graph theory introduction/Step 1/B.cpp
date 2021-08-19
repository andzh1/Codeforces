#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin >> t;
    while(t--) {
        long long n, m;
        cin >> n >> m;
        long long pow[n];
        for(int i = 0; i < n; i++) pow[i] = 0;
        for(int i = 0; i < m; i++) {
            long long a, b;
            cin >> a >> b;
            pow[a-1]++;
            pow[b-1]++;
        }
        for(int i = 0; i < n; i++) cout << pow[i] << " ";
        cout << endl;
    }
}