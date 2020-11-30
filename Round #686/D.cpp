
#include <bits/stdc++.h>
using namespace std;

int main(){

    int TT;
    cin >> TT;
    while(TT--){
        long long n;
        cin >> n;
        int root = sqrt(n);
        int counters[root];
        bool isElementary = true;
        long long constN = n;
        for(int i = 0; i < root; i++) counters[i] = 0;
        for(int ip = 2; ip <= root && ip <= n; ip++){
            while(n % ip == 0 && ip <= n){
                isElementary = false;
                counters[ip-1] ++;
                n /= ip;
            }
        }
        if(isElementary) cout << "1\n" << n << '\n';
        else
        {
            int maximum = 0, ipMax;
            for(int i = 0; i < root; i++) if(counters[i] > maximum){
                maximum = counters[i];
                ipMax = i + 1;
            }
            cout << maximum << '\n';
            for(int i = 0; i < maximum - 1; i++) cout << ipMax << " ";
            maximum --;
            while(maximum--) constN /= ipMax;
            cout << constN << '\n';
        }
        
        

    }
}