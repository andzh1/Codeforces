#include <bits/stdc++.h>
using namespace std;

int lcm(int x, int y) {
    return x*y/__gcd(x, y);
}

int main(){
    int T;
    cin >> T;
    while(T--){
        string s, t;
        cin >> s >> t;
        int length = lcm(s.size(), t.size());
        string lcm1 = "";
        for(int i = 0; i < length/s.size(); i++) lcm1 += s;
        string lcm2 = "";
        for(int i = 0; i < length/t.size(); i++) lcm2 += t;
        cout << ((lcm1 == lcm2)? lcm1  : "-1") << '\n'; 
    }
}