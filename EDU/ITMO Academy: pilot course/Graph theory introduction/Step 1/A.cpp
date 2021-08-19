#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin >> t;
    while(t--) {
        long long n, m;
        cin >> n >> m;
        set<pair<long long, long long>> edges;
        bool ans = true;
        for(long long i = 0; i < m; i++) {
            long long a, b;
            cin >> a >> b;
            if(edges.count({a, b}) != 0 || a == b || b > n || a > n || a < 1 || b < 1) {
                ans = false;
            } 
            edges.insert({a,b});
            edges.insert({b,a});
        }
        ans? cout << "YES" : cout << "NO";
        cout << endl;
    }
}