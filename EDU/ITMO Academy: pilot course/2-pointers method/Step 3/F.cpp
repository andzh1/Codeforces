#include <bits/stdc++.h>
using namespace std;

bool exist(int letter[], int curLetter[]) {
    for(int i = 0; i < 26; i++) {
        if(letter[i] < curLetter[i]) return false;
    }
    return true;
}

int main() {
    long long n, m;
    cin >> n >> m;
    string s, b;
    cin >> s >> b;
    int letter[26];
    for(int i = 0; i < 26; i++) letter[i] = 0;
    for(int i = 0; i < m; i++) {
        letter[b[i]-'a'] ++;
    }
    int curLetter[26];
    for(int i = 0; i < 26; i++) curLetter[i] = 0;
    int l = 0;
    long long ans = 0;
    for(int r = 0; r < n; r++) {
        curLetter[s[r]-'a'] ++;
        while(!exist(letter, curLetter)) {
            curLetter[s[l]-'a']--;
            l++;
        }
        if(exist(letter, curLetter)) ans += r-l+1;
    }
    cout << ans;
}