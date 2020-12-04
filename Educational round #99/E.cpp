#include <bits/stdc++.h>
using namespace std;



int main(){
    int TT;
    cin >> TT;
    while(TT--){
        vector <int> pointsX;
        vector <int> pointsY;
        for(int i = 0; i < 4; i++){
            int a, b;
            cin >> a >> b;
            pointsX.push_back(a);
            pointsY.push_back(b);
        }
        int answer = 0;
        sort(pointsX.begin(), pointsX.end());
        sort(pointsY.begin(), pointsY.end());
        answer += pointsX[1] - pointsX[0] + pointsX[3] - pointsX[2];
        answer += pointsY[1] - pointsY[0] + pointsY[3] - pointsY[2];
        if(pointsY[3] == pointsY[0]) answer = pointsX[3] - pointsX[0] + pointsX[2] - pointsX[1];
        else if(pointsX[3] == pointsX[0]) answer = pointsY[3] - pointsY[0] + pointsY[2] - pointsY[1];
        cout << answer << '\n';
    }
}