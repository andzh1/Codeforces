#include <bits/stdc++.h>
using namespace std;

int main(){

    int TT;
    cin >> TT;
    while(TT--){
        int n;
        cin >> n;
        if(n <= 3) cout << n - 1 << '\n';
        else if(n % 2 == 1) cout << "3\n";
        else cout << "2\n";
    }
}