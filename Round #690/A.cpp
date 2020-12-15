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
        for(int i = 0;  i < n/2; i++) cout << input[i] << " " << input[n-i-1] << " ";
        if(n % 2 == 1) cout << input[n/2] << '\n';
    }
}