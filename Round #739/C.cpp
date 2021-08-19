#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        long k;
        cin >> k;
        int sq = sqrt(k);
        if(k == sq*sq) {
            cout << sq << " 1" << endl; 
        }
        else {
            sq++;
            int mid = sq*sq -sq+1;
            if(k > mid) cout << sq << " " << sq*sq-k+1 << endl;
            else cout << k - (sq*sq-2*sq+2) + 1 << " " << sq << endl;
        }
    }
}