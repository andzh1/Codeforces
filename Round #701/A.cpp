#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--){
        int a, b;
        cin >> a >> b;
        int ans = 1000000000;
        for(int i = 0; i < 500; i++) {
            if(b == 1 && i == 0) continue;
            int nb = b, na = a;
            nb += i;
            int preans = i;
            while(na > 0) {
                na /= nb;
                preans++;
            }
            ans = min(preans, ans);
            if(ans < i) break;
        }
        cout << ans << '\n';
    }
}