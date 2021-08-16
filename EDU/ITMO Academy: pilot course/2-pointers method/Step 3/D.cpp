#include <bits/stdc++.h>
using namespace std;

bool exist(vector <long long> type) {
    for(auto t: type) if(t == 0) return false;
    return true;
}

int main() {
    long long n1;
    cin >> n1;
    long long a[n1];
    for(int i = 0; i < n1; i++) cin >> a[i];
    long long n2;
    cin >> n2;
    long long b[n2];
    for(int i = 0; i < n2; i++) cin >> b[i];
    long long n3;
    cin >> n3;
    long long c[n3];
    for(int i = 0; i < n3; i++) cin >> c[i];
    long long n4;
    cin >> n4;
    long long d[n4];
    for(int i = 0; i < n4; i++) cin >> d[i];
    long long n = n1+n2+n3+n4;
    pair <int, int> input[n];
    for(int i = 0; i < n1; i++) input[i] = {a[i], 0};
    for(int i = 0; i < n2; i++) input[i+n1] = {b[i], 1};
    for(int i = 0; i < n3; i++) input[i+n1+n2] = {c[i], 2};
    for(int i = 0; i < n4; i++) input[i+n1+n2+n3] = {d[i], 3};
    sort(input, input + n);

    long long l = 0, mindif = INT64_MAX;
    pair <long long, long long> answer;
    vector <long long> type (4);
    for(int i = 0; i < 4; i++) type[i] = 0;
    for(int r = 0; r < n; r++) {
        type[input[r].second] ++;
        while(type[input[l].second] > 1) {
            type[input[l].second] --;
            l++;
        }
        if(exist(type)) {
            long long curdif = (input[r].first-input[l].first);
            if(mindif > curdif) {
                mindif = curdif;
                answer = {l, r};
            }
        }
    }
    long long ans[4];
    for(int i = answer.first; i <= answer.second; i++) {
        ans[input[i].second] = input[i].first;
    }
    for(int i = 0; i < 4; i++) cout << ans[i] << " ";
}