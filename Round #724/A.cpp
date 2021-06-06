#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        set <int> input;
        vector <int> a;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a.push_back(x);
            input.insert(x);
        }
        bool exist = false;
        while(!exist && n <= 300) {
            bool toBreak = false;
            for(int i = 0; i < n-1; i++) {
                if(toBreak) break;
                for(int j = i + 1; j < n; j++) {
                    if(toBreak) break;
                    if(input.count(abs(a[i]-a[j])) == 0) {
                        input.insert(abs(a[i]-a[j]));
                        a.push_back(abs(a[i]-a[j]));
                        n++;
                        toBreak = true;
                    }
                    else if(i == n-2 && j == n-1) exist = true;
                }
            }
        }
        if(!exist) cout << "NO\n";
        else {
            cout << "Yes\n";
            cout << n << '\n';
            for(int i = 0; i < n; i++) cout << a[i] << " ";
            cout << '\n';
        }
        
    }
}