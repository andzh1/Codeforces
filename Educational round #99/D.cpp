#include <bits/stdc++.h>
using namespace std;

int countA(int x, int input[], int n){
    bool isRaising = true;
    for(int i = 1; i < n; i++)
        if(input[i] < input[i-1]){
            isRaising = false;
            break;
        }
    if(isRaising) return 0;
    else
    {
        int ipX = -1;
        for(int i = n-1; i >= 0; i--)
            if(input[i] > x){
                ipX = i;
            }
        if(ipX == -1) return -1;
        else {
            swap(input[ipX], x);
            int answer = countA(x, input, n);
            if(answer == -1) return -1;
            else return answer + 1;
        }
    }
    
}

int main(){
    int TT;
    cin >> TT;
    while(TT--){
        int n, x;
        cin >> n >> x;
        int input[n];
        for(int i = 0; i < n; i++) cin >> input[i];
        cout << countA(x, input, n) << '\n';
    }
}