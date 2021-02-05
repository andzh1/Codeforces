#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n, k;
        cin >> n >> k;
        if(n > k) {
            if(n % k != 0) cout << "2" << '\n';
            else cout << "1" << '\n';
        }
        else if(k % n == 0) cout << k/n << '\n';
        else cout << k/n + 1 << '\n';

         
    }
}