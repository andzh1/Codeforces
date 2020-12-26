#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int summ = 0;
        int input[3];
        for(int i = 0; i < 3; i++){
            cin >> input[i];
            summ += input[i];
        }
        sort(input, input + 3);
        if(summ % 9 != 0) cout << "No\n";
        else
        {
            if(input[0]*9 < summ) cout << "no\n";
            else cout << "yes\n";
        }
         
    }
}