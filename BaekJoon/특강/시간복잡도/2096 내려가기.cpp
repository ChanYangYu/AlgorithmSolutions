#include <bits/stdc++.h>
#define ll long long

using namespace std;
int mp[100001][3];
int dp[2][3];
int n;

int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","rt",stdin);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n;
    
    for(int i = 0; i < n; i++)
    	for(int j = 0; j < 3; j++)
    		cin>>mp[i][j];
    
    int max_res = -987654321;
    
    dp[0][0] = mp[0][0];
    dp[0][1] = mp[0][1];
    dp[0][2] = mp[0][2];
    
    for(int i = 1; i < n; i++){
    	for(int j = 0; j < 3; j++){
    		int mx;
    		if(j == 0)
    			mx = max(dp[0][j], dp[0][j+1]);
			else if(j == 1){
				mx = max(dp[0][j], dp[0][j-1]);
				mx = max(mx, dp[0][j+1]);
			}
			else
				mx = max(dp[0][j], dp[0][j-1]);
			dp[1][j] = mp[i][j] + mx;
		}
		dp[0][0] = dp[1][0];
		dp[0][1] = dp[1][1];
		dp[0][2] = dp[1][2];
	}
	
	max_res = max(dp[0][0], dp[0][1]);
	max_res = max(max_res, dp[0][2]);
	
	int min_res = 987654321;
	dp[0][0] = mp[0][0];
    dp[0][1] = mp[0][1];
    dp[0][2] = mp[0][2];
    
	for(int i = 1; i < n; i++){
    	for(int j = 0; j < 3; j++){
    		int mn;
    		if(j == 0)
    			mn = min(dp[0][j], dp[0][j+1]);
			else if(j == 1){
				mn = min(dp[0][j], dp[0][j-1]);
				mn = min(mn, dp[0][j+1]);
			}
			else
				mn = min(dp[0][j], dp[0][j-1]);
			dp[1][j] = mp[i][j] + mn;
		}
		dp[0][0] = dp[1][0];
		dp[0][1] = dp[1][1];
		dp[0][2] = dp[1][2];
	}
    
    min_res = min(dp[0][0], dp[0][1]);
	min_res = min(min_res, dp[0][2]);
    cout<<max_res<<" "<<min_res;
}
