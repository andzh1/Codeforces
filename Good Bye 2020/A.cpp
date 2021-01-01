#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int input[n];
        for(int i = 0; i < n; i++) cin >> input[i];
        set <int> ans;
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++) ans.insert(input[j] - input[i]);
        }
        cout << ans.size() << '\n';
    }
}