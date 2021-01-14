#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> money) {
    ios_base::sync_with_stdio(false);
    int answer = 0;
    vector<vector<int> > dy(money.size(), vector<int>(2,0));
    
    dy[0][0] = money[0];
    dy[1][0] = max(money[0],money[1]);
    dy[1][1] = money[1];
    
    //a[i] = max(a[i-1], a[i-2] + money)
    for(int i = 2; i < money.size(); i++){
        dy[i][0] = max(dy[i-1][0], dy[i-2][0] + money[i]);
        dy[i][1] = max(dy[i-1][1], dy[i-2][1] + money[i]);
    }
    
    return max(dy[money.size()-2][0], dy[money.size()-1][1]);
}
