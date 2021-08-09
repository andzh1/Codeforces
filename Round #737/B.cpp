#include <bits/stdc++.h>
using namespace std;

int main() {
    int test;
    cin >> test;
    while(test--) {
        int n, k;
        cin >> n >> k;
        int input[n];
        for(int i = 0; i < n; i++) cin >> input[i];
        map <int, int> numbers;
        int pattern[n];
        for(int i = 0; i < n; i++) pattern[i] = input[i];
        for(int i = 0; i < n; i++) numbers[input[i]] = i;
        sort(pattern, pattern+n);
        int shift = 0, curnum = 0;
        for(int ip = 0; ip < n; ip++) {
            int i = numbers[pattern[ip]]+1;
            while(input[i] == pattern[ip+1] && i < n && ip < n-1) {i++; shift++; ip++;}
            curnum++;
        }
        if(k - curnum >= 0 && k - curnum <= shift) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}