#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    int numbers[3];
    cin >> numbers[0] >> numbers[1] >> numbers[2];
    int maxSol = 0;
    sort(numbers, numbers + 3); 
    if(n % numbers[0] == 0) cout << n / numbers[0];
    else {
        for(int i = 0;  i <= n / numbers[0]; i++){
            for(int j = 0; j <= n / numbers[1]; j++){
                int k = n - i*numbers[0] - j*numbers[1];
                if(k % numbers[2] == 0 && k >= 0) {
                    maxSol = max(maxSol, i + j + k/numbers[2]);
                    // cout << i << " " << j << '\n';
                }
            }
        }
        cout << maxSol;
    }
}