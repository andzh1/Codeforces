#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    map <string, int> base;
    while(n--){
        string s;
        cin >> s;
        if(base.count(s)) {
            cout << s << base[s] << '\n';
            base[s]++;

        }
        else
        {
            base[s] = 1;
            cout << "OK\n";
        }
    }
}