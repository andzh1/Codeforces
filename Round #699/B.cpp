#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        int h[n];
        for(int i = 0; i < n; i++) cin >> h[i];
        // int cursum = 0;
        int newh[n];
        newh[n-1] = h[n-1];
        for(int i = n-1; i >= 1; i--) {
            if(newh[i] > h[i-1]) {
                newh[i-1] = newh[i]; 
            }
            else {
                newh[i-1] = h[i-1];
            }
        }
        int sum = 0;
        for(int i = 0; i < n-1; i++) sum += newh[i] - h[i];
        if(sum < k) cout << "-1\n";
        else {
            int ans;
            for(int i = 0; i < k && k != 0; i++){
                for(int j = 0; j < n-1; j++) {
                    if(h[j] >= h[j+1]) continue;
                    else {
                        h[j]++;
                        ans = j + 1;
                        break;
                    }
                }
            }
            cout << ans << '\n';
        }
        // for(int i = 1; i < n; i++){
        //     if(h[i] > h[i-1]) {
        //         int sum = 0;
        //         for(int j = i-1; j >= 0; j--){
        //             if()
        //         }
        //     }
        // }
    }
}