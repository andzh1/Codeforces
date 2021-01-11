#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;
        int param[n];
        for(int i = 0; i < n; i++) cin >> param[i];
        int presents[m];
        for(int i = 0; i < m; i++) cin >> presents[i];
        for(int i = 0; i < n; i++) 
            param[i] = presents[param[i]-1];
        sort(param, param + n);
        int a = 0, x = n - 1;
        while(a < m){
            if(param[x] < presents[a]) break;
            else {
                param[x] = presents[a];
                a++;
                x--;
            }
        }
        long long sum = 0;
        for(int i = 0; i < n; i++) sum += param[i];
        cout << sum << '\n';
    }
}