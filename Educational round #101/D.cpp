#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n; 
        set <int> dontProceed;
        vector <int> row;
        int x = n;
        while(x > 2) {
            dontProceed.insert(x);
            row.push_back(x);
            if(sqrt(x) == (int)sqrt(x)) x = (int)sqrt(x);
            else x = (int)sqrt(x) + 1;
        }
        row.push_back(2);
        cout << n-2 + dontProceed.size() << '\n';
        for(int i = 3; i < n; i++){
            if(!dontProceed.count(i)) cout << i << " " << n << '\n';
        }
        for(int i = 0; i < row.size() - 1; i++){
            cout << row[i] << " " << row[i+1] << '\n';
            cout << row[i] << " " << row[i+1] << '\n';
        }
    }
}