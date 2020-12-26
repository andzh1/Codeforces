#include <bits/stdc++.h>
#include <cassert>
using namespace std;

long long binominalCoefficient(long long n, long long k){
    if(n-k > k) k = n - k;
    long long answer = 1;
    int ip = 2;
    for(int i = n; i > k && ip <= (n-k+1); i--) {
        answer *= i;
        while(answer % ip == 0 && ip <= (n-k)){
            answer /= ip; ip++;
        }
        answer %= (long long)1000000007;
    }
    return answer;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int k, m;
        int n;
        cin >> n >> m >> k;
        int input[n];
        for(int i = 0; i < n; i++) {
            cin >> input[i]; 
        }   
        if(n < m) cout << "0\n";
        else {
            sort(input, input + n);
            int a = 0, b = m-1;
            long long answer = 0;
            while(b < n){
                if(input[b] - input[a] <= k) b++;
                else if(b - a >= m){
                    answer += binominalCoefficient(b-a-1, m-1);
                    answer %= 1000000007;
                    a++;
                }
                else {a++; b++;}
            }
            if(b-a >= m) answer += binominalCoefficient(b-a, m);
            answer %= 1000000007;
            cout << answer << '\n';
        }   
    }
}
