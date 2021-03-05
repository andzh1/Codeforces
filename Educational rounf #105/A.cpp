#include <bits/stdc++.h>
using namespace std;

bool check(string s) {
    int dif = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(') dif++;
        else dif--;
        if(dif < 0) return false;
    }
    if(dif == 0) return true;
    else return false;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        string s;
        cin >> s;
        int a = 0, b = 0, c = 0;
        char first = s[0], last = s[s.length() - 1];
        s[0] = '(';
        s[s.length() - 1] = ')';
        if(first == last) cout << "No\n";
        else {
            for(int i = 0; i < s.length(); i++) {
                if(s[i] == first) s[i] = '(';
                if(s[i] == last) s[i] = ')';
            }
            string s1 = s, s2 = s;
            for(int i = 0; i < s1.length(); i++) {
                if(s1[i] != '(' && s1[i] != ')') s1[i] = '(';
            }
            for(int i = 0; i < s2.length(); i++) {
                if(s2[i] != '(' && s2[i] != ')') s2[i] = ')';
            }
            bool ans = check(s1) + check(s2);
            if(ans) cout << "YES\n";
            else cout << "no\n";
        }
        
    }
}