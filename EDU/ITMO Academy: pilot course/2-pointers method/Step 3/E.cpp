#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, s;
    cin >> n >> s;
    long long weight[n];
    long long cost[n];
    for(int i = 0; i < n; i++) cin >> weight[i];
    for(int i = 0; i < n; i++) cin >> cost[i];
    long long l = 0, maxCost = 0, curWeight = 0, curCost = 0;
    for(int r = 0; r < n; r++) {
        curWeight += weight[r];
        curCost += cost[r];
        while(curWeight > s) {
            curWeight -= weight[l];
            curCost -= cost[l];
            l++;
        }
        if(curWeight <= s) maxCost = max(maxCost, curCost);
    }
    cout << maxCost;
}