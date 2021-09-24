#include <iostream>
#include <math.h>

int main() {
    long long n, p, q;
    std::cin >> n >> p >> q;
    long long a[n];
    long long maxEl = 0; 
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
        maxEl = std::max(maxEl, a[i]);
    }
    if(p == q) {
        std::cout << (maxEl + q - 1)/q;
    } else {
        long long l = 0, r = (maxEl + q - 1)/q, ans = r;
        p -= q;
        while(r - l > 1) {
            long long kickNumber = (r+l)/2;
            long long numbOfAdds = 0;
            for(int i = 0; i < n; i++) {
                if(a[i] > q*kickNumber) {
                    numbOfAdds += ((a[i]-q*kickNumber)+(p-1))/p;
                }
            }
            if(numbOfAdds > kickNumber) l = kickNumber;
            else {
                r = kickNumber;
                ans = std::min(kickNumber, ans);
            }
        }
        std::cout << ans;
    }
}