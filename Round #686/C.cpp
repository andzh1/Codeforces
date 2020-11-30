#include <bits/stdc++.h>
using namespace std;

int main(){

    int TT;
    cin >> TT;
    while(TT--){
        int n;
        cin >> n;
        int input[n];
        int amounts[n];
        for(int i = 0; i < n; i++) amounts[i] = n+1;
        // vector <int> pointers[n];
        cin >> input[0];
        amounts[input[0] - 1] = 1;
        for(int i = 1; i < n; i++) {
            cin >> input[i];
            if(amounts[input[i]-1] == n+1) amounts[input[i]-1] = 0;
            if(input[i-1] != input[i]) amounts[input[i]-1] ++;
        }
        amounts[input[0]-1]--;
        amounts[input[n-1]-1]--;
        sort(amounts, amounts + n);
        cout << amounts[0] + 1 << '\n';
        

    }
}