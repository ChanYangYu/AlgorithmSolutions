#include <bits/stdc++.h>
using namespace std;
int m, n;
int mp[501][501];
int cache[501][501];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int solve(int y, int x)
{
	int& ret = cache[y][x];
	
	//목적지 도착했으면 1리턴 
	if(y == m-1 && x == n-1)
		return ret = 1;

	//이미 구한 위치면 해당 값 리턴 
	if(ret != -1)
		return ret;
	
	ret = 0;
	
	//갈 수 있는 모든 길 탐색 
	for(int i = 0; i < 4; i++){
		int yy = y + dy[i];
		int xx = x + dx[i];
		
		if(yy >= m || yy < 0 || xx >= n || xx < 0)
			continue;
		if(mp[y][x] > mp[yy][xx])
			ret += solve(yy, xx);
	}
	
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt","rt",stdin);
	
	cin>>m>>n;
	
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			cin>>mp[i][j];
	
	memset(cache, -1, sizeof(cache));
	int res = solve(0,0);
	
	cout<<res;
	return 0;
}
