#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        pair <int, int> input[n];
        for(int i = 0; i < n; i++) {
            cin >> input[i].first >> input[i].second;
        }
        int positions[n+1];
        positions[0] = 0;
        for(int i = 0;  i < n; i++)
        {
            int ip = i + 1;
            while(input[ip].first - input[i].first < abs(input[i].second - positions[i]) && ip < n)
            {
                if(input[i].second - positions[i] > 0) positions[ip] = positions[i] + input[ip].first - input[i].first;
                else positions[ip] = positions[i] - (input[ip].first - input[i].first);
                ip++;
            } 
            positions[ip] = input[i].second;
            i = ip - 1;
        }
        int answer = 0;
        for(int i = 0; i < n; i++){
            if(input[i].second >= min(positions[i], positions[i+1]) && 
               input[i].second <= max(positions[i], positions[i+1])) answer ++;
        }
        cout << answer << '\n';
    }
}