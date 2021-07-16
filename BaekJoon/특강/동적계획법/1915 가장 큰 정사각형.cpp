#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

char mp[1001][1001];
int cache[1001][1001];
int n, m;

int solve(int y , int x){
	int& ret = cache[y][x];
	
	if(ret != -1)
		return ret;
	
	if(x+1 > m || mp[y][x+1] == '0')
		return ret = 1;
	if(y+1 > n || mp[y+1][x] == '0')
		return ret = 1;
	if(mp[y+1][x+1] =='0')
		return ret = 1;

	int right = solve(y, x+1);
	int down = solve(y+1, x);
	int diag = solve(y+1, x+1);
	
	int res = min(right, down);
	res = min(res, diag);
	
	ret = 1 + res;
	
	
	return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","rt",stdin);
    cin.tie(0);
    cout.tie(0);
    
    vector<pii> ones;
    
    cin>>n>>m;
    
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++){
    		cin>>mp[i][j];
    		
    		if(mp[i][j] == '1')
    			ones.push_back({i,j});
		}
	}
	
	int res = 0;
	
	memset(cache, -1, sizeof(cache));
	for(int i = 0; i < ones.size(); i++){
		int y = ones[i].first;
		int x = ones[i].second;
		
		res = max(res, solve(y, x));
	}
	
	cout<<res*res;
    return 0;
}
