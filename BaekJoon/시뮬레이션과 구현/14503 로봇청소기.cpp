#include <bits/stdc++.h>
#define MAX 987654321
using namespace std;
//각 방향의 왼쪽 위치를 담음 
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int mp[51][51];
int ch[51][51];

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	int n, m;
	int ry, rx, rd;
	
	cin>>n>>m;
	
	cin>>ry>>rx>>rd;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin>>mp[i][j];
			//벽은 방문처리 
			if(mp[i][j] == 1)
				ch[i][j] = 1;
		}
	}
	//시작 위치 청소 
	int res = 1;
	ch[ry][rx] = 1;
	while(1){
		int i;
		//네 방향 검토 
		for(i = 0; i < 4; i++){
			//방향 이동 
			if(rd-1 < 0)
				rd = 3;
			else
				rd -= 1;
			int yy = dy[rd] + ry;
			int xx = dx[rd] + rx;
				
			if(ch[yy][xx] == 0){
				ch[yy][xx] = 1;
				ry = yy;
				rx = xx;
				res++;
				break;
			}
		}
		//네 방향 모두 없으면 
		if(i == 4){
			ry = ry - dy[rd];
			rx = rx - dx[rd];
			if(mp[ry][rx] == 1)
				break;
		}
	}
	cout<<res;
	return 0;
}
