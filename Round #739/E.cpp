#include <bits/stdc++.h>
using namespace std;

string del(string s, char ch) {
    string ans = "";
    for(int i = 0; i < s.length(); i++) {
        if(s[i] != ch) ans.push_back(s[i]);
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        string que = "";
        set <char> letters;
        int numlet[26];
        for(int i = 0; i < 26; i++) {
            numlet[i] = 0;
        }
        for(int i = s.length() - 1; i > -1; i--) {
            if(letters.count(s[i]) == 0) {
                que.push_back(s[i]);
                letters.insert(s[i]);
            }
            numlet[s[i]-'a']++;
        }
        int anslength = 0;
        bool possible = true;
        for(int i = 0; i < que.length()/2; i++) {
            swap(que[i], que[que.length()-1-i]);
        }
        for(int i = que.length() - 1; i > -1; i--) {
            anslength += numlet[que[i]-'a']/(i+1);
            if(numlet[que[i]-'a'] % (i+1) != 0) possible = false;
        }
        
        string q = s.substr(0, anslength);
        string preans = q;
        for(int i = 0; i < que.length(); i++) {
            q = del(q, que[i]);
            preans += q;
        }    

        if(possible && preans == s) cout << s.substr(0, anslength) << " " << que << endl;
        else cout << "-1" << endl;

    }
}