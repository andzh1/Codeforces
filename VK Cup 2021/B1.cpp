#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    pair <int, int> input[n];
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        input[i] = {max(a, b), min(a, b)};
    }
    int ans = 0;
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(input[i].first == input[j].first || input[i].second == input[j].first || input[i].first == input[j].second || input[i].second == input[j].second) ans++;
        }
    }
    cout << ans << '\n';
}