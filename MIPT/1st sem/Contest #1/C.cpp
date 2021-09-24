#include <iostream>
#include <stack>

int main() {
    std::ios::sync_with_stdio(false), 
    std::cin.tie(nullptr), 
    std::cout.tie(nullptr);
    int n;
    std::cin >> n;    
    long long h[n];
    for(int i = 0; i < n; i++) {
        std::cin >> h[i];
    }
    long long l[n];
    long long r[n];
    std::stack <int> left;
    l[0] = -1;
    for(int i = 1; i < n; i++) {
        if(h[i] > h[i-1]) {
            l[i] = i-1;
            left.push(i-1);
        }
        else {
            while(!left.empty() && h[i] <= h[left.top()]) left.pop();
            if(left.empty()) {
                l[i] = -1;
            } else {
                l[i] = left.top();
            }
            left.push(i);
        }
    }
    std::stack <int> right;
    r[n-1] = n;
    for(int i = n-2; i >= 0; i--) {
        if(h[i] > h[i+1]) {
            r[i] = i+1;
            right.push(i+1);
        }
        else {
            while(!right.empty() && h[i] <= h[right.top()]) right.pop();
            if(right.empty()) {
                r[i] = n;
            } else {
                r[i] = right.top();
            }
            right.push(i);
        }
    }

    long long ans = r[0]*h[0];
    if(ans < (n-1-l[n-1])*h[n-1]) ans = (n-1-l[n-1])*h[n-1];
    for(int i = 1; i < n-1; i++) {
        long long preans = h[i]*(r[i]-l[i]-1);
        if(preans > ans) ans = preans;
    }
    std::cout << ans;
}