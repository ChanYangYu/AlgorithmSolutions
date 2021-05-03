#include <bits/stdc++.h>
using namespace std;
int mp[501][501];
int cache[501][501];
int n;

int solve(int h, int w){
	if(h == n)
		return 0;
	
	int& ret = cache[h][w];
	if(ret != -1)
		return ret;
		
	ret = solve(h+1, w) + mp[h][w];
	ret = max(ret, solve(h+1, w+1) + mp[h][w]);
	
	return ret;
}
int main() {
	cin.tie(0);
	//freopen("input.txt", "rt", stdin);
	
	cin>>n;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= i; j++){
			cin>>mp[i][j];
		}
	}
	
	memset(cache, -1, sizeof(cache));
	
	cout<<solve(0,0);
	return 0;
}
