#include <bits/stdc++.h>
using namespace std;

int main() {
    int test;
    cin >> test;
    while(test--) {
        int n;
        cin >> n;
        int input[n];
        for(int i = 0; i < n; i++) cin >> input[i];
        sort(input, input + n);
        long long sum = 0;
        for(int i = 0; i < n-1; i++) sum += input[i];
        cout << setprecision(17) << (double)(input[n-1] + (double)sum/(n-1)) << endl;
    }
}