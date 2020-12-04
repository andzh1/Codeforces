#include <bits/stdc++.h>
using namespace std;

int main(){
    int TT;
    cin >> TT;
    while(TT--){
        int n, m;
        cin >> n >> m;
        int inputX[n], inputY[m];
        for(int i = 0; i < n; i++) cin >> inputX[i];
        for(int i = 0; i < m; i++) cin >> inputY[i];
        int counter = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) if(inputX[i] == inputY[j]) counter ++;
        }
        cout << counter << '\n';
    }
}