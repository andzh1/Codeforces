#include <bits/stdc++.h>
using namespace std;

int main(){
    int m, s;
    cin >> m >> s;
    if(s == 0){
        if(m == 1) cout << "0 0\n";
        else cout << "-1 -1\n";
    }
    else if(s > 9*m) cout << "-1 -1\n";
    else 
    {
        string answer = "";
        int counter = 0;
        while(s > 9){
            answer.push_back('9');
            s -= 9;
            counter ++;
        }
        if(m - counter == 1) cout << s << answer << " " << answer << s << '\n';
        else
        {
            cout << "1";
            for(int i = 0; i < m - counter - 2; i++) cout << "0";
            cout << s-1 << answer << " " << answer << s;
            for(int i = 0; i < m - counter - 1; i++) cout << "0";
            cout << '\n';
        }
        
    }
    
}