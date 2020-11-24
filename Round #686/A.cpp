#include <bits/stdc++.h>
using namespace std;

int main(){

    int TT;
    cin >> TT;
    while(TT--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            cout << (i+1)%n + 1<< " ";
        }
        cout << '\n';

    }
}