#include <bits/stdc++.h>
using namespace std;

int main() {
    bool locked = false;
    string color = "blue";
    int n;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        if(s == "lock") locked = true;
        else if(s == "unlock") locked = false;
        else if(!locked) color = s;
    }
    cout << color << '\n';
}