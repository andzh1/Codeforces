#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        long long A, B, n;
        cin >> A >> B >> n;
        long long monster[n];
        long long maxat = 0;
        for(int i = 0; i < n; i++) {
            cin >> monster[i];
            maxat = max(maxat, monster[i]);
        }
        B += maxat;
        long long b[n];
        for(int i = 0; i < n; i++) cin >> b[i];
        for(int i = 0; i < n && B > 0; i++) {   
            b[i] = (b[i] + A - 1)/A;
            B -= (long long)(b[i]*monster[i]);
        }
        if(B > 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
