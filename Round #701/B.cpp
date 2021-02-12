#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q, k;
    cin >> n >> q >> k;
    int input[n];
    for(int i = 0; i < n; i++) cin >> input[i];
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--; r--;
        int ans = max(0, k + input[r] - input[l] - 2*(r-l)-1);
        cout << ans << '\n';
    }
    
}