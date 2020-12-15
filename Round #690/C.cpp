#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        if(n > 45) cout << "-1\n";
        else if(n == 45) cout << "123456789\n";
        else
        {
            int maxDigit = 9;
            string answer;
            while(n >= maxDigit) {
                n -= maxDigit;
                answer.push_back('0' + maxDigit);
                maxDigit --;
            }
            if(n != 0) answer.push_back('0' + n);
            for(int i = answer.size() - 1;  i >= 0; i-- ) cout << answer[i];
            cout << '\n';
        }
        
    }
}