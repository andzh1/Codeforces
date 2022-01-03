#include <bits/stdc++.h>

using namespace std;

struct Segment
{
    int left;
    int right;
    int cost;

    bool operator==(const Segment& other) const {
        return left == other.left && right == other.right;
    }

    bool operator!=(const Segment& other) const {
        return !(*this == other);
    }

    bool operator>(const Segment& other) const {
        return left < other.left || right > other.right;
    }
};



int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        Segment input[n];
        for (int i = 0; i < n; ++i) {
            cin >> input[i].left >> input[i].right >> input[i].cost;
        }
        Segment minLeft = input[0];
        Segment maxRight = input[0];
        Segment maxLen = input[0];
        cout << input[0].cost << '\n';
        // pair<Segment, Segment> answer[n];
        // answer[0] = {input[0], input[0]};
        for (int s = 1; s < n; ++s) {
            // answer[s] = answer[s - 1];
            if (input[s].left < minLeft.left) minLeft = input[s];
            if (input[s].left == minLeft.left && input[s].cost < minLeft.cost) minLeft = input[s];
            if (input[s].right > maxRight.right) maxRight = input[s];
            if (input[s].right == maxRight.right && input[s].cost < maxRight.cost) maxRight = input[s];
            if (input[s].left == minLeft.left && input[s].right == maxRight.right) {
                if (input[s] == maxLen) {
                    if (maxLen.cost > input[s].cost) maxLen = input[s];
                } else {
                    maxLen = input[s];
                }
            } 
            if (maxLen.left == minLeft.left && maxLen.right == maxRight.right) {
                cout << min(maxLen.cost, minLeft.cost + maxRight.cost) << '\n';
            } else {
                cout << minLeft.cost + maxRight.cost << '\n';
            }
        }
        // for (int s = 0; s < n; ++s) {
        //     int toPrint = answer[s].first.cost + answer[s].second.cost;
        //     if (answer[s].first == answer[s].second) toPrint = min(answer[s].first.cost, answer[s].second.cost);
        //     cout << toPrint << '\n';
        // }
    }
}



/*

*/