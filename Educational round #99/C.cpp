#include <bits/stdc++.h>
using namespace std;

int main(){
    int TT;
    cin >> TT;
    while(TT--){
        int a,b;
        cin >> a >> b;
        if(b == 0) cout << a << " 0\n";
        else if (a == 0) cout << "0 " << b << '\n';
        cout << a-1 << " " << b << '\n';
    }
}