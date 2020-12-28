#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        int left = s.find('(');      
        int right = s.find(')');      
        if(right == 0 || left == s.length() - 1) cout << "NO\n";
        else if(s.length() % 2 == 1) cout << "NO\n";
        else cout << "YES\n";
    }
}