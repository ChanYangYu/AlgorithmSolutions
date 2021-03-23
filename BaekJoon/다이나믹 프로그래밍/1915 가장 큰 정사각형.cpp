#include <bits/stdc++.h>
using namespace std;
int cache[1001][1001];
char mp[1001][1001];
int n, m;

int solve(int y, int x){
	int& ret = cache[y][x];
	
	if(ret != -1)
		return ret;
	
	//최댓값이 1인 경우 
	if(y+1 >= n || x+1 >= m)
		return ret = 1;
	
	//오른쪽 방향
	if(mp[y][x+1] == '0')
		return ret = 1;
	//아래 방향 
	if(mp[y+1][x] == '0')
		return ret = 1;
	//대각선 방향 
	if(mp[y+1][x+1] == '0')
		return ret = 1; 
	
	int right = solve(y, x+1) + 1;
	int down = solve(y+1, x) + 1;
	int diag = solve(y+1, x+1) + 1;
	
	ret = min(right, down);
	ret = min(ret, diag);
	
	return ret; 
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	
	cin>>n>>m;
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin>>mp[i][j];
	
	memset(cache, -1, sizeof(cache));
	
	int res = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			//1인 모든 시작위치 탐색 
			if(mp[i][j] == '1'){
				int tmp = solve(i, j);
				//최대 크기 인경우 
				if(tmp > res)
					res = tmp;
			}
		}
	}
	
	//넓이 출력 
	cout<<res*res;
	return 0;
}
