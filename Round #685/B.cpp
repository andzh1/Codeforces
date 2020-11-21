#include <bits/stdc++.h>
using namespace std;

int main(){
    int TT;
    cin >> TT;
    while(TT--){
        int n, q;
        cin >> n >> q;
        string input;
        cin >> input;
        int prefixPopcounts[n];
        prefixPopcounts[0] = input[0] - '0';
        for(int i = 1; i < n; i++)
            prefixPopcounts[i] = prefixPopcounts[i-1] + input[i] - '0';
        while(q --){
            int leftPointer, rightPointer;
            cin >> leftPointer >> rightPointer;
            leftPointer--; rightPointer--;
            bool answer = false;
            if(leftPointer > 0){
                if(input[leftPointer] == '1' && prefixPopcounts[leftPointer-1] != 0) answer = true;
                if(input[leftPointer] == '0' && prefixPopcounts[leftPointer-1] < leftPointer) answer = true;
            }
            if(rightPointer < n-1){
                if(input[rightPointer] == '1' && prefixPopcounts[n-1] != prefixPopcounts[rightPointer]) answer = true;
                if(input[rightPointer] == '0' && prefixPopcounts[rightPointer] + n - rightPointer - 1 > prefixPopcounts[n-1]) answer = true;
            }
            if(answer) cout << "YES\n";
            else cout << "NO\n";
            
        }
    }
}