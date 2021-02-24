#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
   
    int t;
    cin >> t;
    while(t--) {
        ll p, a, b, c;
        cin >> p >> a >> b >> c;
        ll ta = (a - (p%a))%a;
        ll tb = (b - (p%b))%b;
        ll tc = (c - (p%c))%c;
        cout << min(min(ta, tb), tc) << '\n';
    }
        
}