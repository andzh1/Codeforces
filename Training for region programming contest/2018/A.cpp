#include <bits/stdc++.h>
using namespace std;

int main(){
    long l, r, a;
    cin >> l >> r >> a;
    long long ans = 0;
    for(int i = l; i < l+a && i + a <= r; i++){
        long long k = (r-i)/a;
        ans += k*(k+1)/2; 
    }
    cout << ans;
}