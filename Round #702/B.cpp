#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        int r[3];
        r[0] = 0;
        r[1] = 0;
        r[2] = 0;
        for(int i = 0; i < n; i ++) {
            int a;
            cin >> a;
            r[a%3]++;
        }
        int ipmax, max = 0;
        for(int i = 0; i < 3; i++) {
            if(r[i] > max) {
                max = r[i];
                ipmax = i;
            }
        }
        
        int newr[3];
        newr[2] = r[(2+ipmax)%3];
        newr[1] = r[(1+ipmax)%3];
        newr[0] = r[ipmax];
        if(newr[0] == newr[2]){
            swap(newr[1], newr[2]);
        }
        if(newr[1] >= newr[2]) cout << newr[0]*2 + newr[1] - n << '\n';
        else {
            if(newr[2] <= n/3) cout << newr[0]*2 + newr[1] - n << '\n';
            else cout << newr[2]*2 + newr[0] - n << '\n';
        }
    }
}