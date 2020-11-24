#include <bits/stdc++.h>
using namespace std;

int main(){

    int TT;
    cin >> TT;
    while(TT--){
        int n;
        cin >> n;
        int input[n], x;
        int a[n];
        for(int i = 0; i < n; i++) input[i] = 0;
        for(int i = 0; i < n; i++) {
            cin >> x;
            a[i] = x;
            input[x-1] ++; 
        }
        x = -1;
        for(int i = 0; i < n; i++){
            if(input[i] == 1){
                x = i+1;
                break;
            }
        }
        for(int i = 0; i < n; i++) if(a[i] == x) cout << i+1 << '\n';
        if(x < 0) cout << "-1\n";
    }
}