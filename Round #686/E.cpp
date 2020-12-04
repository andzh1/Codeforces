#include <bits/stdc++.h>
using namespace std;

//I wrote this solotion after reading an official solution on https://codeforces.com/blog/entry/84984

int main(){
    int TT;
    cin >> TT;
    while(TT--){
        int n;
        cin >> n;
        vector <int> graph[n];
        for(int i = 0; i < n; i++){
            int a,b;
            cin >> a >> b;
            graph[a-1].push_back(b-1);
            graph[b-1].push_back(a-1);
        }
        queue <int> leafs;
        long long counts[n];
        for(int i = 0; i < n; i++) counts[i] = 0;
        int sizeOfLoop = n;
        for(int i = 0; i < n; i++) {
            if(graph[i].size() == 1) 
            {
                leafs.push(i);
                sizeOfLoop--;
            }
            counts[i] = 1;
        }
        while (!leafs.empty()){
            int currentLeaf = leafs.front();
            leafs.pop();
            int newLeaf = graph[currentLeaf][0];
            for(int i = 0; i < graph[newLeaf].size(); i++) 
                if(graph[newLeaf][i] == currentLeaf) {
                    graph[newLeaf].erase(graph[newLeaf].begin()+i); 
                    break;
                }
            counts[newLeaf] += counts[currentLeaf];
            counts[currentLeaf] = -1;
            if(graph[newLeaf].size() == 1) {
                leafs.push(newLeaf);
                --sizeOfLoop;
            }
        }
        long long answer = 0;
        for(int i = 0; i < n; i++){
            if(counts[i] > 0) answer += counts[i]*(counts[i]-1)/2 + counts[i]*(n-counts[i]);
        }
        // answer += sizeOfLoop*(sizeOfLoop - 1);
        cout << answer << '\n';
    }   

