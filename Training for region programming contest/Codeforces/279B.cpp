#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, t;
    cin >> n >> t;
    int input[n];
    for(int i = 0; i < n; i++) cin >> input[i];
    int summ = input[0], a = 0, b = 0, maxLength = 0;
    while(b < n){
        if(summ <= t) {
            if(b < n - 1){
                b++;
                summ += input[b];
            } 
            else break;
        }
        else {
            maxLength = max(maxLength, b - a);
            summ -= input[a];
            a++;
            // if(a > b) b++;
        }
    }
    maxLength = max(maxLength, b - a + 1);
    cout << maxLength << '\n';
}