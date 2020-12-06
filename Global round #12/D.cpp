#include <bits/stdc++.h>
using namespace std;

int main(){
    int TT;
    cin >> TT;
    while(TT--){
        int n;
        cin >> n;
        int input[n];
        for(int i = 0; i < n; i++) cin >> input[i];
        bool answers[n];
        answers[n-1] = true;
        int a = 0, b = n - 1;
        for(int i = n - 1; i > 0 && b >= a; i--){
            if(input[a] == n - i) {
                answers[i-1] = answers[i];
                a++;
            }
            else if(input[b] == n - i) {
                answers[i-1] = answers[i];
                b--;
            }
            else {
                answers[i-1] = false;
            }
        }
        answers[0] = true;
        int newInput[n];
        for(int i = 0; i < n; i++) newInput[i] = input[i];
        sort(newInput, newInput + n);
        int ipMax = -1;
        for(int i = 0; i < n; i++){
            if(newInput[i] != i+1){
                ipMax = i;
                break;
            }
        }
        if(ipMax == -1) ipMax = n;
        for(int i = 0; i < n - ipMax; i++) answers[i] = false;
        for(int i = 0; i < n; i++ ) cout << answers[i];
        cout << '\n';
    }
}
