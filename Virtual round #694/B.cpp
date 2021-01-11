#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n, x;
        cin >> n >> x;
        long long sum = 0;
        queue <pair <int, long>> input;
        for(int i = 0; i < n; i++) {
            int a;
            cin >> a;
            sum += a;
            input.push({a, 1});
        }
        while(!input.empty()) {
            pair <int, long> q = input.front();
            input.pop();
            if(q.first % x != 0) {
                cout << sum << '\n';
                break;
            }
            sum += q.first * q.second;
            input.push({q.first/x, x*q.second});
        }
    }
}