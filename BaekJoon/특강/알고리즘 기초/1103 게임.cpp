#include <bits/stdc++.h>
#define ll long long
using namespace std;

char mp[51][51];
int cache[51][51];
int ch[51][51];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
bool has_cycle = false;
int n, m;

int solve(int y, int x){
	int& ret = cache[y][x];
	
	if(ret != -1)
		return ret;
	
	ret = 0;
	
    //사방으로 체크 
    for(int i = 0; i < 4; i++){
        int num = mp[y][x] - '0';
        int yy = y + (num * dy[i]);
        int xx = x + (num * dx[i]);

        //범위 벗어난 경우 
        if(yy < 1 || yy > n || xx < 1 || xx > m)
            continue;
        //구멍에 들어간 경우 
        if(mp[yy][xx] == 'H')
            continue;

        //순환이 생기는 경우 
        if(ch[yy][xx] == 1){
            has_cycle = true;
            return 0;
        }

        //방문체크 
        ch[yy][xx] = 1;
        ret = max(ret, solve(yy, xx) + 1);

        //이후 탐색에서 사이클이 생긴경우 
        if(has_cycle == true)
            return 0;

        //방문체크 취소
        ch[yy][xx] = 0;
    }
    
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "rt", stdin); 

    cin>>n>>m;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin>>mp[i][j];

    ch[1][1] = 1;
    memset(cache, -1, sizeof(cache));
    int res = solve(1,1) + 1;

    if(has_cycle)
        cout<<"-1";
    else
        cout<<res;

    return 0;
}
