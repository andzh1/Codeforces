#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n % 2 == 1) {
            for(int i = 1; i <= n - 1; i++) {
                for(int j = i + 1; j <= n; j++) {
                    if((i + j) % 2 == 1) cout << "1 ";
                    else cout << "-1 ";
                }
            }
        }
        else {
            for(int i = 1; i <= n - 1; i++) {
                for(int j = i + 1; j <= n; j++) {
                    if(i % 2 == 1 && j == i+1) cout << "0 ";
                    else if((i + j) % 2 == 1) cout << "1 ";
                    else cout << "-1 ";
                }
            }
        }
    }
}