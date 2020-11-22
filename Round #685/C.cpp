#include <bits/stdc++.h>
using namespace std;

int main(){
    int TT;
    cin >> TT;
    while(TT--){
        int n, k;
        cin >> n >> k;
        string a, b;
        cin >> a >> b;
        int counter[26][2];
        for(int i = 0; i < 26; i++){
            counter[i][0] = 0;
            counter[i][1] = 0;
        }
        for(int i = 0; i < n; i++){
            counter[a[i]-'a'][0] ++;
            counter[b[i]-'a'][1] ++;
        }
        bool isPossible = true;
        int dif = 0;
        for(int i = 25; i >= 0 && isPossible; i-- ){
            if(abs(counter[i][1] - counter[i][0]) % k != 0) isPossible = false;
            dif += counter[i][1] - counter[i][0];
            if(dif < 0) isPossible = false;
        }
        if(isPossible) cout << "Yes\n";
        else cout << "No\n";
    }
}