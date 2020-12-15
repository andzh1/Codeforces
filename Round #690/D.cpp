#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int input[n];
        int summ = 0;
        for(int i = 0; i < n; i++) {
            cin >> input[i];
            summ += input[i];
        }   
        vector <int> dividersOfSumm;
        int oldSumm = summ;
        for(int i = 1;  i <= (int)sqrt(summ); i++){
            if(summ % i == 0){
                dividersOfSumm.push_back(summ/i);
                dividersOfSumm.push_back(i);
                // summ /= i;
            }
        }
        sort(dividersOfSumm.begin(), dividersOfSumm.end());
        for(auto currentSumm: dividersOfSumm){
            long s = 0, ip = -1;
            while(ip < n){
                if(s < currentSumm){
                    ip++; 
                    s += input[ip];
                }
                else if(s == currentSumm) s = 0;
                else if(s > currentSumm) break;
            }
            if(ip == n){
                cout << n - oldSumm/currentSumm << '\n';
                break;
            }
        }
    }
}