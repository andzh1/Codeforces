#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        long long a, b, c;
        cin >> a >> b >> c;
        long long x = a + b + c;
        std::cout << !(x % 3 == 0) << '\n';
    }
}