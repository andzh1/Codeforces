#include <bits/stdc++.h>

using namespace std;

struct elem {
    char liked;
    int rating;
    int pos;

    bool operator<(const elem& second) {
        if (liked != second.liked) return liked < second.liked;
        return rating < second.rating;
    }
};

int main() {
    long long T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int rate[n];
        for (int i = 0; i < n; ++i) cin >> rate[i];
        string s;
        cin >> s;
        elem answer[n];
        for (int i = 0; i < n; ++i) {
            answer[i].liked = s[i];
            answer[i].rating = rate[i];
            answer[i].pos = i;
        }
        sort(answer, answer + n);
        int toPrint[n];
        for (int i = 0; i < n; ++i) {
            toPrint[answer[i].pos] = i + 1;
        }
        for (int i = 0; i < n; ++i) {
            cout << toPrint[i] << ' ';
        }
        cout << '\n';
    }
}