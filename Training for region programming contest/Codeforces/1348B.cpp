#include <bits/stdc++.h>
using namespace std;

int main(){
    int TT;
    cin >> TT;
    while(TT--){
        int n, k;
        cin >> n >> k;
        int input[n];
        set <int> numbers;
        for(int i = 0; i < n; i++) {
            cin >> input[i];
            numbers.insert(input[i]);
        }
        sort(input, input + n);
        int maxEqual = 1, currentEqual = 1;
        for(int i = 1; i < n; i++){
            if(input[i] == input[i-1]) currentEqual++;
            else
            {
                maxEqual = max(maxEqual, currentEqual);
                currentEqual = 1;
            }
        }
        maxEqual = max(maxEqual, currentEqual);
        vector <int> preLoop;
        for(auto x: numbers) preLoop.push_back(x);
        while(preLoop.size() < k) preLoop.push_back(1);
        if(numbers.size() > k) cout << "-1";
        else {
            cout << k*n << '\n';
            for(int i = 0; i < n; i++){
                for(auto x: preLoop) cout << x << " ";
            }
        }
        cout << '\n';
    }   
}