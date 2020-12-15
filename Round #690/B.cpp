#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        string s;
        int n;
        cin >> n;
        cin >> s;
        bool answer = false;
        for(int i = 0; i <= 4; i++){
            if(s.substr(0, i) + s.substr(n - 4 + i, 4 - i) == "2020") answer = true;
        }
        (answer)? cout << "YES\n" : cout << "NO\n";
    }
}