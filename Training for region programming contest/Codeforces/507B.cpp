#include <bits/stdc++.h>
using namespace std;

int main(){
    long long r, x1, y1, x2, y2;
    cin >> r >> x1 >> y1 >> x2 >> y2;
    long double x = sqrt(abs(x2 - x1)*abs(x2 - x1) + abs(y2 - y1)*abs(y2 - y1));
    r *= 2;
    long double answer = x/r;
    if(answer - (long)answer != 0) answer ++;
    cout << (long)answer << '\n';
}