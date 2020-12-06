#include <bits/stdc++.h>
using namespace std;

int main(){
    int TT;
    cin >> TT;
    while(TT--){
        int n;
        cin >> n;
        string input[n];
        for(int i = 0; i < n; i++) cin >> input[i];
        bool isin[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) isin[i][j] = false;
        }
        for(int i = 0; i < n; i++){
            for(int j = 1; j < n-1; j++) {
                if(input[i][j] == '.') continue;
                if(input[i][j-1] == input[i][j] && input[i][j+1] == input[i][j]) {
                    isin[i][j] = true;
                    isin[i][j+1] = true;
                    isin[i][j-1] = true;
                }
            }
        }
        for(int i = 1; i < n-1; i++){
            for(int j = 0; j < n; j++) {
                if(input[i][j] == '.') continue;
                if(input[i-1][j] == input[i][j] && input[i+1][j] == input[i][j]) {
                    isin[i][j] = true;
                    isin[i-1][j] = true;
                    isin[i+1][j] = true;
                }
            }
        }
        int count[3];
        count[0] = 0;
        count[1] = 0;
        count[2] = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                count[(i+j)%3] += isin[i][j];
            }
        }
        int ipMin = 0, minc = count[0];
        for(int k = 1; k < 3; k++){
            if(count[k] < minc){
                minc = count[k];
                ipMin = k;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isin[i][j]){
                    if((i + j)%3 == ipMin) input[i][j] = 'O';
                }
            }
            cout << input[i] << '\n';
        }
        
    }
}
