#include <bits/stdc++.h>
using namespace std;

int closestPowerOf2(int x){
    int logx = (int)log2(x);
    int y1 = x - (1<<(logx));
    int y2 = (1<<(logx+1)) - x;
    if(x >= 805306368) return 1<<logx;
    if(y1 <= y2) return 1<<logx;
    return 1<<(logx+1);
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            cout << closestPowerOf2(x) << " ";
        }
        cout << '\n';
    }
}