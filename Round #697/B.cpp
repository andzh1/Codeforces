#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int x = n % 2020;
        int y = n/2020;
        if(x <= y) cout << "YES\n";
        else cout << "NO\n";
    }
}