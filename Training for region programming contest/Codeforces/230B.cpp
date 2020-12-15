#include <bits/stdc++.h>
using namespace std;

int main(){
    bool isElementary[1000001];
    for(int i = 0; i <= 1000000; i++) isElementary[i] = true;
    isElementary[1] = false;
    for(int i = 2; i <= 1000000; i++){
        if(isElementary){
            for(int j = 2*i; j <= 1000000; j += i) isElementary[j] = false;
        }
    }
    int n;
    cin >> n;
    while(n--){
        long long x;
        cin >> x;
        long long sqrtx = sqrt(x);
        if(x == sqrtx*sqrtx && isElementary[sqrtx]) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }
}