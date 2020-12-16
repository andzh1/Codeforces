#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    pair <int, int> input[n];
    for(int i = 0; i < n; i++){
        cin >> input[i].first >> input[i].second;
    }
    sort(input, input + n);
    int currentDay = input[0].second;
    for(int i = 1; i < n; i++){
        if(input[i].second >= currentDay) currentDay = input[i].second;
        else currentDay = input[i].first;
    }
    cout << currentDay << '\n';
}