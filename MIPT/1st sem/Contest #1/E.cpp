#include <iostream>
#include <stack>
#include <queue>
#include <math.h>

int main() {
    /*std::ios::sync_with_stdio(false), 
    std::cin.tie(nullptr), 
    std::cout.tie(nullptr);*/
    int n, m, l;
    std::cin >> n >> m >> l;
    int A[n][l];
    int B[m][l];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < l; j++) 
            std::cin >> A[i][j];
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < l; j++) 
            std::cin >> B[i][j];
    }
    int q;
    std::cin >> q;
    for(int i = 0; i < q; i++) {
        int a, b;
        std::cin >> a >> b;
        a--; b--;
        int left = 0, right = l;
        int k = 0;
        int ans = std::max(A[a][0], B[b][0]);
        if(std::max(A[a][l-1], B[b][l-1]) < ans) {
            ans = std::max(A[a][l-1], B[b][l-1]);
            k = l-1;
        }
        while(right-left > 1) {
            int ip = (left+right)/2;
            if(A[a][ip] >= B[b][ip]) {
                right = ip;
            } 
            else left = ip;
            if(ans > std::max(A[a][ip], B[b][ip])) {
                ans = std::max(A[a][ip], B[b][ip]);
                k = ip;
            }
        }
        std::cout << k+1 << '\n';
    }
    
}