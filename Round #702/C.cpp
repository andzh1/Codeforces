#include <bits/stdc++.h>
using namespace std;

bool solve(long long n){
    double p = pow(n, 1.0/3.0);
    for(long long i = 1; i <= p+1; i++) {
        long long x = n - i*i*i;
        if(x < 1) break;
        long long y = pow(x, 1.0/3.0);
        if (x == y*y*y || x == (y+1)*(y+1)*(y+1)) return true;
    }
    return false;
}

int main(){
    int T;
    cin >> T;
    while(T--) {
        long long n;
        cin >> n;
        bool ans = solve(n);
        (ans)? cout << "YES\n" : cout << "NO\n";
    }
}