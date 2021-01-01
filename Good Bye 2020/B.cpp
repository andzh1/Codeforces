#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int input[n];
        for(int i = 0; i < n; i++) cin >> input[i];
        int amount = 1;
        for(int i = 1; i < n; i++){
            if(input[i] != input[i-1]) amount ++;
            else
            {
                int ip = i + 1;
                while(input[ip] == input[i] && ip < n) ip++;
                ip--;
                amount ++;
                input[ip]++;
                i = ip;
            }
            
        }
        cout << amount << '\n';
    }
}