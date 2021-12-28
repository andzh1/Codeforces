#include <bits/stdc++.h>

using namespace std;

int main() {
    long long T;
    cin >> T;
    while (T--) {
        long long n, k;
        cin >> n >> k;
        long long input[n];
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> input[i];
            sum += input[i];
        }
        if (sum <= k) {
            cout << "0\n";
            continue;
        }
        if (sum == k + 1) {
            cout << "1\n";
            continue;
        }
        if (n == 1) {
            cout << input[0] - k << '\n';
            continue;
        }
        sort(input, input + n);
        long long sufsum = 0;
        long long minElem = input[0];
        long long minAns = INT64_MAX;
        sum -= minElem;
        for (int i = n - 1; i > 0; --i) {
            sum -= input[i];
            long long cursum = k - sum;
            long long currentMin = (llabs(cursum) + n - i) / (n - i + 1);
            if (cursum < 0) currentMin = -currentMin;
            // if (currentMin * (n - i + 1) > cursum && cursum < 0) currentMin--;
            if (currentMin * (n - i + 1) > cursum) currentMin--;
            long long currentAns = (n - i) + max(0ll, (minElem - currentMin));
            minAns = min(minAns, currentAns);
        }
        cout << minAns << '\n';
    }
}