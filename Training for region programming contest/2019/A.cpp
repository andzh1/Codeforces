#include <bits/stdc++.h>
using namespace std;



int main(){
    long long n;
    cin >> n;
    if(n == 1 || n == 4) cout << "No\n";
    else if(n == 0) cout << "Yes\n" << "1 1\n";
    else
    {
        if(n % 2 == 1) {
            cout << "Yes\n" << (n+1)/2 << " " << n/2 << '\n';
        }
        else 
            if(n % 4 == 2) 
                cout << "No\n";
        else 
            cout << "Yes\n" << n/4 + 1 << " " << n/4 - 1 << '\n';    
    }
}