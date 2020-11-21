#include <bits/stdc++.h>
using namespace std;

int main(){

    int TT;
    cin >> TT;
    while(TT--){
        int x, y;
        cin >> x >> y;
        cout << x + y + max(abs(x-y) - 1, 0) << '\n';
    }
}