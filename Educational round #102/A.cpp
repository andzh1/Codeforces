#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n, d;
        cin >> n >> d;
        bool exists = true;
        int min1 = 101, min2 = 101;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            if(a > d) exists = false;
            if(a < min1) {
                min2 = min1;
                min1 = a;
            }
            else if(a < min2) min2 = a;
        }
        cout << ((exists || min1 + min2 <= d)? "Yes\n" : "No\n");
    }
}