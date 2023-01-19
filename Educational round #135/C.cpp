#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    // vector<int> a(n), b(n);
    vector<pair<int, int>> a(n), b(n);
    vector<int> digitsA (10), digitsB (10);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        a[i].second = s.length();
        a[i].first = std::stoll(s);
        if (a[i].first < 10) digitsA[a[i].first]++;
    }
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        b[i].second = s.length();
        b[i].first = std::stoll(s);
        if (b[i].first < 10) digitsB[b[i].first]++;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ia = n - 1, ib = n - 1, ans = 0;
    while (ia >= 0 && ib >= 0 && a[ia].first > 9 && b[ib].first > 9) {
        if (a[ia] == b[ib]) {
            --ia;
            --ib;
            continue;
        } else if (a[ia] > b[ib]) {
            digitsA[a[ia].second]++;
            --ia;
            ++ans;
            continue;
        } else if (a[ia] < b[ib]) {
            digitsB[b[ib].second]++;
            --ib;
            ++ans;
            continue;
        } 
    }
    while (ia >= 0 && a[ia].first > 9) {
        digitsA[a[ia].second]++;
        ++ans;
        --ia;
    }
    while (ib >= 0 && b[ib].first > 9) {
        digitsB[b[ib].second]++;
        ++ans;
        --ib;
    }
    for (int i = 9; i >= 2; --i) {
        ans += abs(digitsA[i] - digitsB[i]);
    }
    cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    // freopen("tests.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tests = 1;
    cin >> tests;
    while(tests--) solve();
}
