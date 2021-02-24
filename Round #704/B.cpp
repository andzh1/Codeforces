#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
   
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        int input[n];
        for(int i = 0; i < n; i++) cin >> input[i];
        pair <int, int> arr [n];
        for(int i = 0; i < n; i++) arr[i] = {input[i], i};
        sort(arr, arr + n);
        int last = n, ip = n-1;
        for(int ip = n-1; ip >= 0 && last > 0; ip--) {
            int x = arr[ip].second;
            if(x >= last) continue;
            for(int i = x; i < last; i++) cout << input[i] << " ";
            last = x;
        }
        cout << '\n';

    }
        
}