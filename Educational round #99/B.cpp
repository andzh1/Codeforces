#include <bits/stdc++.h>
using namespace std;

int main(){
    int TT;
    cin >> TT;
    while(TT--){
        int x;
        cin >> x;
        double n = (sqrt(8*x + 1) - 1)/2;
        long long y;
        if(n == (int)n) y = (int)n;
        else y = (int)n + 1;
        if(y*(y+1)/2 - x == 1) cout << y+1 << '\n';
        else cout << y << '\n';
    }
}