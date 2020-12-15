#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int newN = n;
    int x;
    vector <int> div, undiv;
    while(n--){
        cin >> x;
        (x % 2 == 1)? undiv.push_back(newN - n) : div.push_back(newN - n);
    }
    (undiv.size() > 1)? cout << div[0] << '\n' : cout << undiv[0] << '\n';
}