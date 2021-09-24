#include <iostream>
#include <stack>
#include <math.h>
#include <vector>


std::pair <std::vector <int>, long long> merge(std::vector <int> input) // [left, right)
{ 
    if(input.size() == 2) {
        if(input[0] > input[1]) {
            int t = input[0];
            input[0] = input[1];
            input[1] = t;
            return {input, 1};
        } else {
            return {input, 0};
        }
    } else {
        std::vector <int> first (input.size()/2);
        std::vector <int> second (input.size()/2);
        for(int i = 0; i < input.size()/2; i++) first[i] = input[i];
        for(int i = input.size()/2; i < input.size(); i++) second[i-input.size()/2] = input[i];
        std::pair <std::vector <int>, long long> firstHalf = merge(first);
        std::pair <std::vector <int>, long long> secondHalf = merge(second);
        int ans = firstHalf.second + secondHalf.second;
        int ipf = 0, ips = 0;
        while(ips < input.size()/2 && ipf < input.size()/2) {
            if(firstHalf.first[ipf] > secondHalf.first[ips]) {
                input[ips + ipf] = secondHalf.first[ips];
                ans += input.size()/2 - ipf;
                ips++;
            } else {
                input[ips + ipf] = firstHalf.first[ipf];
                ipf++;
            }
        }
        for(; ipf < input.size()/2; ipf++) {
            input[ipf + ips] = firstHalf.first[ipf];
        }
        for(; ips < input.size()/2; ips++) {
            input[ipf + ips] = secondHalf.first[ips];
        }
        return {input, ans};
    }
}

int main() {
    long long n;
    std::ios::sync_with_stdio(false), 
    std::cin.tie(nullptr), 
    std::cout.tie(nullptr);
    freopen("inverse.in", "r", stdin);
    freopen("inverse.out", "w", stdout);
    std::cin >> n;
    if(n == 1) {
        std::cout << "0\n";
    } else {
        int m = 1<<((int)log2(2*n - 1));
        std::vector<int> a(m);
        for(int i = 0; i < n; i++) 
            std::cin >> a[i];
        for(int i = n; i < m; i++) 
            a[i] = INT32_MAX;
        std::pair <std::vector <int>, long long> answer = merge(a);
        std::cout << answer.second;
    }
    
    
}