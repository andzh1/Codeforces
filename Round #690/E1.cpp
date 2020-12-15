#include <bits/stdc++.h>
using namespace std;

long long C2(long long n){
    return n*(n-1)/2;
}

long long C3(long long n){
    return n*(n-1)*(n-2)/6;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int k = 2, m = 3;
        int n;
        cin >> n;
        int input[n];
        for(int i = 0; i < n; i++) {
            cin >> input[i]; 
        }   
        if(n < 3) cout << "0\n";
        else {
            sort(input, input + n);
            int a = 0, b = 0;
            long long answer = 0;
            while(a <= b && b < n){
                if(input[b] - input[a] <= k) b++;
                else
                {
                    if(b - a >= m) answer += C2(b - a - 1);
                    a++; 
                } 
            }
            if(input[b-1] - input[a] <= k && b - a >= m) answer += C3(b - a);
            cout << answer << '\n';
        }
    }
}