#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

/*
	점화식
	dp[n][k] = dp[n-1][k] + dp[n][k-1]
	
	-> k개를 뽑고 현재값이 n-1인 경우 1을 추가하면 성립한다.(중복으로 뽑을 수 있기 때문에 k개중 하나를 1 더큰값 선택하면 됨)
	-> k-1개를 뽑고 현재값이 n인 경우 0을 뽑으면 성립한다. 
*/
int cache[5001][5001];

int solve(int cur, int cnt){
	if(cur == 0){
		return 1;
	}
	if(cnt == 1){
		return 1;
	}	
	
	int& ret = cache[cur][cnt];
	
	if(ret != -1){
		return ret;
	}
	
	return ret = (solve(cur-1, cnt) + solve(cur, cnt-1))%1000000000;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,k;
    
    cin>>n>>k;
    
    memset(cache, -1, sizeof(cache));
    cout<<solve(n, k);
	
    return 0;
}
