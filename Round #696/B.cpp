#include <bits/stdc++.h>
using namespace std;

int main(){
    bool elementary[21001];
    for(int i = 2; i <= 21000; i++) elementary[i] = true;
    for(int i = 2; i <= 21000; i++){
        if(elementary[i]) {
            for(int j = 2*i; j <= 21000; j += i) elementary[j] = false;
        }
    }
    int T;
    cin >> T;
    while(T--){
        int d;
        cin >> d;
        if(d == 1) cout << "6\n";
        else if(d == 2) cout << "15\n";
        else {
            long long ans1 = 1, ans = 1;
            for(long long i = d+1; i <= 21000; i++){
                if(elementary[i]) {
                    ans *= i;
                    ans1 = i*i*i;
                    break;
                }
            }
            for(long long i = ans+d; i <= 21000; i++){
                if(elementary[i]) {
                    ans *= i;
                    break;
                }
            }
            cout << min(ans1, ans) << '\n';
        }
    }
}