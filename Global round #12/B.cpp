#include <bits/stdc++.h>
using namespace std;

int manhettenDistance(pair <int, int> a, pair <int, int> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main(){
    int TT;
    cin >> TT;
    while(TT--){
        int n, k;
        cin >> n >> k;
        vector <pair <int, int>> points;
        for(int i = 0; i < n; i ++){
            int a, b;
            cin >> a >> b;
            points.push_back({a,b});
        }
        vector <int> adj[n];
        for(int i = 0; i < n - 1; i++)
        {
            for(int j = i + 1; j < n; j++){
                if(manhettenDistance(points[i], points[j]) <= k){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        bool answer = false;
        for(int i = 0; i < n; i++){
            if(adj[i].size() == n-1) answer = true;
        }
        if(answer) cout << "1\n";
        else cout << "-1\n";
    }
}
