#include <bits/stdc++.h>
using namespace std;
int cache[1<<16][16];
int adj[16][16];
int n;

int solve(int state, int pos, int start){
	int& ret = cache[state][pos];
    //방문 체크
	if(ret != -1)
		return ret;
    //모든 정점 방문완료	
	if(state == ((1<<n)-1)){
        //처음점으로 돌아갈 수 있는경우
		if(adj[pos][start] != 0)
			return ret = adj[pos][start];
		//처음 정점으로 돌아갈 수 없는 경우
        else
			return ret = 987654321;
	}
	
	ret = 987654321;
    //현재 정점에서 다른 정점으로 최단 경로 탐색
	for(int i = 0; i < n; i++){
		if(adj[pos][i] != 0 && (state & (1<<i)) == 0)
			ret = min(ret, solve((state | (1<<i)), i, start) + adj[pos][i]);
	}
	
	return ret;
}
int main(){   
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin>>adj[i][j];
	
	int res = 987654321;
	memset(cache, -1, sizeof(cache));
	res = min(res, solve(1, 0, 0));
	cout<<res;
    return 0;
}
