#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int limit[n];
    for(int i = 0; i < n; i++) cin >> limit[i];
    int length[n];
    for(int i = 0; i < n; i++) cin >> length[i];
    int m;
    cin >> m;
    int border[m-1];
    for(int i = 0; i < m-1; i++ ) cin >> border[i];
    int fee[m];
    for(int i = 0; i < m; i++ ) cin >> fee[i];
    double feeTime[m];
    feeTime[0] = 0;
    for(int j = 0; j < n; j++){
        feeTime[0] += (double)length[j]/limit[j];
    }
    for(int i = 1; i < m; i++) {
        feeTime[i] = 0;
        for(int j = 0; j < n; j++){
            feeTime[i] += (double)length[j]/(limit[j] + border[i]);
        }
    }
    int q;
    cin >> q;
    while(q--){
        int s, t;
        cin >> s >> t;
        int time = t - s;
        if(time > feeTime[0]) cout << "0\n";
        else if(time < feeTime[m-1]) cout << fee[m-1] << '\n';
        else
        {
            for(int i = 1; i < m; i++){
                if(feeTime[i] < time && feeTime[i-1] > time) cout << fee[i] << '\n';
            }
        }
        
    }
/* 
3                                                                           
10 20 30
400 500 600
6
1 5 10 12 16
100 300 600 800 1000 1500
3
10 100
20 70
45 100 


*/

}