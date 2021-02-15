#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int input[n];
        for(int i = 0; i < n; i++) cin >> input[i];
        sort(input, input + n);
        int ans = n-1;
        int ip = 1;
        while(input[ip] == input[ip-1] && ip < n) {ans--; ip++;}
        cout << ans << '\n';
    }
}