#include <bits/stdc++.h>
using namespace std;
int dp[100001][3];
int sticker[100001][2];
 
int main(){   
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	int t;
	
	cin>>t;
	
	for(int k = 0; k < t; k++){
		int n;
		
		cin>>n;
		for(int i = 0; i < n; i++)
			cin>>sticker[i][0];
		for(int i = 0; i < n; i++)
			cin>>sticker[i][1];
		
		dp[0][0] = 0;
		dp[0][1] = sticker[0][0];
		dp[0][2] = sticker[0][1];
		
		for(int i = 1; i < n; i++){
			dp[i][0] = max(dp[i-1][1], dp[i-1][2]);
			dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + sticker[i][0];
			dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + sticker[i][1];
			
			//cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<"\n";
		}
		
		int res = max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
		cout<<res<<"\n";	
	}
    return 0;
}
