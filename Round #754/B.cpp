#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int prefix1 = 0;
        int suffix0 = 0;
        for(int i = 0; i < n; i++) {
            suffix0 += s[i] == '0';
        }
        int ip = 0;
        while(prefix1 != suffix0) {
            if(s[ip] == '0') suffix0--;
            else prefix1++;
            ip++;
        }
        int count = 0;
        for (int i = 0; i <= ip; i++) {
            count += s[i] == '1';
        }
        for (int i = ip; i < n; i++) {
            count += s[i] == '0';
        }
        if (count <= 1) cout << "0\n";
        else {
            cout << "1\n";
            cout << count << ' ';
            for (int i = 0; i <= ip; i++) {
                if(s[i] == '1') cout << i+1 << ' ';
            }
            for (int i = ip; i < n; i++) {
                if(s[i] == '0') cout << i+1 << ' ';
            }
            cout << '\n';
        }
        
    }
}