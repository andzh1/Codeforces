#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--) {
        int px, py;
        cin >> px >> py;
        string s;
        cin >> s;
        int xmax = 0, xmin = 0, ymax = 0, ymin = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'U') ymax++;
            if(s[i] == 'D') ymin--;
            if(s[i] == 'L') xmin--;
            if(s[i] == 'R') xmax++;
            // xmax = max(xmax, x);
            // xmin = min(xmin, x);
            // ymax = max(ymax, y);
            // ymin = min(ymin, y);
        }
        if(xmin <= px && px <= xmax && ymin <= py && py <= ymax) cout << "Yes\n";
        else cout << "No\n";
    }
}