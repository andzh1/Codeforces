#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        string b;
        cin >> b;
        string d = b;
        bool prev1 = false;
        for(int i = 0; i < n; i++){
            if(b[i] == '0'){
                if(prev1) {
                    d[i] = '0';
                    prev1 = false;
                }
                else {
                    d[i] = '1';
                    prev1 = true;
                }
            }
            else {
                if(prev1) {
                    d[i] = '2';
                    prev1 = false;
                }
                else {
                    if(i == 0) d[i] = '2';
                    else {
                        if(d[i-1] == '0') d[i] = '2';
                        else {
                            d[i] = '1';
                            prev1 = true;
                        }
                    }
                }
            }
        }
        string a = b;
        for(int i = 0; i < n; i++) a[i] = '0' + d[i] - b[i];
        cout << a << '\n';
    }
}