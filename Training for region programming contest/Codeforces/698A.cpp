#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int input[n];
    for(int i = 0; i < n; i++) cin >> input[i];
    int amountOfBreaks = 0;
    if(input[0] == 0) amountOfBreaks = 1;
    for(int i = 1; i < n; i++){
        if(input[i] == 0) {
            amountOfBreaks ++;
        }
        else if(input[i] == 3){
            input[i] = 3 - input[i-1];
        }
        else if(input[i] == input[i-1]){
            input[i] = 0;
            amountOfBreaks++;
        }
    }
    cout << amountOfBreaks << '\n';
}