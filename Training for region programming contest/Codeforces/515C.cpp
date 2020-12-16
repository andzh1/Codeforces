#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int counter2 = 0, counter3 = 0, counter5 = 0, counter7 = 0;
    for(int i = 0; i < n; i++){
        switch (s[i])
        {
        case '2':
            counter2 ++;
            break;
        case '3':
            counter3 ++;
            break;
        case '4':
            counter2 += 2;
            counter3 ++;
            break;
        case '5':
            counter5 ++;
            break;
        case '6':
            counter5 ++;
            counter3 ++;
            break;
        case '7':
            counter7 ++;
            break;
        case '8':
            counter7 ++;
            counter2 += 3;
            break;
        case '9':
            counter7 ++;
            counter3 += 2;
            counter2 ++;
            break;
        default:
            break;
        }
    }
    for(int i = 0; i < counter7; i++) cout << "7";
    for(int i = 0; i < counter5; i++) cout << "5";
    for(int i = 0; i < counter3; i++) cout << "3";
    for(int i = 0; i < counter2; i++) cout << "2";
    cout << '\n';
}