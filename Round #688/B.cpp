#include <bits/stdc++.h>
using namespace std;

int main(){
    int TT;
    cin >> TT;
    while(TT--){
        int n;
        cin >> n;
        int input[n];
        for(int i = 0; i < n; i++) {
            cin >> input[i];
        }
            long long dif = 0;
            for(int i = 1; i < n; i++) dif += abs(input[i] - input[i-1]);
            long long maxDif = 0, curDif;
            for(int i = 1; i < n-1; i++){
                curDif = abs(input[i] - input[i-1]) + abs(input[i+1] - input[i]) - abs(input[i+1] - input[i-1]);
                if(maxDif < curDif) maxDif = curDif;
            }
            curDif = abs(input[0] - input[1]);
            if(maxDif < curDif) maxDif = curDif;
            curDif = abs(input[n-1] - input[n-2]);
            if(maxDif < curDif) maxDif = curDif;
            cout << dif - maxDif << '\n';        
    }
}