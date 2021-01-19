#include <bits/stdc++.h>
using namespace std;

int main(){
    long k;
    cin >> k;
    if(k == 0) cout << "0\n";
    else if(k % 4 == 2) cout << "none\n";
    else
    {
        bool isPositive = k > 0;
        k = abs(k);
        bool exists = false;
        for(int i = sqrt(k); i >= 1; i-- ){
            if(k % i == 0 && i % 2 == (k/i) % 2) {
                if(isPositive) cout << (i + k/i)/2 << '\n';
                else cout << (-i + k/i)/2 << '\n';
                exists = true;
                break;
            }
        }
        if(!exists) {
            cout << "none\n";
        }
    }
    
    
}