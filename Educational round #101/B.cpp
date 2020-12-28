#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n; 
        int red[n];
        for(int i = 0; i < n; i++) cin >> red[i];
        int m;
        cin >> m;
        int blue[m];
        for(int i = 0; i < m; i++) cin >> blue[i];
        int prefixReds[n], prefixBlues[m];
        prefixReds[0] = red[0], prefixBlues[0] = blue[0];
        for(int i = 1; i < n; i++) prefixReds[i] = prefixReds[i-1] + red[i];
        for(int i = 1; i < m; i++) prefixBlues[i] = prefixBlues[i-1] + blue[i];

        int maxRed = -101, maxBlue = -101;
        for(int i = 0; i < n; i++) maxRed = max(maxRed, prefixReds[i]);
        for(int i = 0; i < m; i++) maxBlue = max(maxBlue, prefixBlues[i]);
        cout << max(max(0, maxRed + maxBlue), max(maxRed, maxBlue)) << '\n';
    }
}