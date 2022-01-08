#include <bits/stdc++.h>

using namespace std;

int dp[100001][2];

int solution(vector<int> sticker)
{
    int answer = 0;
    int n = sticker.size();
    
    if(n == 1) return sticker[0];

    dp[0][1] = sticker[0];
    dp[1][1] = sticker[0];
    dp[1][0] = sticker[1];

    
    for(int i = 2; i < n; i++){
        if(i == n-1)
            dp[i][1] = dp[i-1][1];
        else
            dp[i][1] = max(dp[i-1][1], dp[i-2][1] + sticker[i]);
        
        dp[i][0] = max(dp[i-1][0], dp[i-2][0] + sticker[i]);
    }

    return max(dp[n-1][0], dp[n-1][1]);
}
