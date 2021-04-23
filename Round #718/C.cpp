#include <bits/stdc++.h>
using namespace std;

int main() {
    
        int n; cin >> n;
        vector <int> p (n);
        for(int i = 0; i < n; i++) cin >> p[i];
        vector <int> diag [n];
        diag[n-1] = p;
        for(int i = n-2; i >= 0; i--)  {
            vector <int> curdiag;
            vector <int> anc = diag[i+1];
            for(int j = 0; j < i+2; j++) {
                anc[j]--;
                if(anc[j] > 0) curdiag.push_back(anc[j]);
            }
            diag[i] = curdiag;
        }
        for(int i = n-1; i >= 0; i--) {
            for(int j = 0; j < i+1; j++) {
                diag[i][j] += n-1-i;
            }
        }
        for(int i = n-1; i >= 0; i--) {
            int k = i;
            while(k <= n-1) {
                cout << diag[k][k-i] << " ";
                k++;
            }
            cout << '\n';
        }
    
}