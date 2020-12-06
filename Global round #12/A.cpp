#include <bits/stdc++.h>
using namespace std;

int main(){
    int TT;
    cin >> TT;
    while(TT--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        string answer1 = "", answer2 = "";
        for(int i = 0; i < n; i++) {
            if(s[i] == 'u') answer1 += 'u';
            else answer2 += s[i];
        }
        cout << answer1 + answer2 << '\n';
    }
}
