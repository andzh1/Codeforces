#include <bits/stdc++.h>
using namespace std;

int main(){
    long n, a, b, c;
    cin >> n >> a >> b >> c;
    long maxa, maxb, maxc, maxim = 0;
    for(long i = a; i < n; i += a){
        for(long j = b; j < n; j+= b){
            long k = n - i - j;
            if(k < 0) continue;
            int cur = (c/k)*(b/j)*(a/i);
            if(maxim < cur) {
                    maxim = cur;
                    maxa = i;
                    maxb = j;
                    maxc = k;
                }
        }
        for(long j = c; j < n; j += c){
            long k = n - i - j;
            if(k < 0) continue;
            int cur = (b/k)*(c/j)*(a/i);
            if(maxim < cur) {
                    maxim = cur;
                    maxa = i;
                    maxb = k;
                    maxc = j;
                }
        }
    }
    cout << maxa << " " << maxb << " " << maxc;
}