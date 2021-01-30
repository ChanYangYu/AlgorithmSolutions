#include <bits/stdc++.h>
using namespace std;

int mp[300][300];
int mp1[300][300];
int ch[300][300];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int main(void){
	ios_base::sync_with_stdio(false);
	int n,m, res = 0;
	cin>>n>>m;
	
	//빙산값 입력 
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin>>mp[i][j]; 
	
	while(1){
		int check = 1;
		//모두 녹았는지 검토 
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(mp[i][j] != 0){
					//체크값 0으로 변경 
					check = 0;
					break;
				}
			}
			if(check == 0)
				break;
		}
		
		//모두 녹았으면 반복문 탈출 
		if(check){
			//결과값 0으로 초기화 
			res = 0;
			break;
		}
		
		//방문배열 초기화 
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				ch[i][j] = 0;
		
		//현재 빙산그룹 탐색
		int group = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(ch[i][j] == 0 && mp[i][j] != 0){
					group++;
					ch[i][j] = group;
					
					queue<pair<int, int> > q;
					
					q.push(make_pair(i,j));
					while(!q.empty()){
						int y = q.front().first;
						int x = q.front().second;
						
						q.pop();
						
						//4방향 검토
						for(int k = 0; k < 4; k++){
							int yy = y + dy[k];
							int xx = x + dx[k];
							
							//범위 체크 
							if(yy < 0 || xx < 0 || yy >= n || xx >= m)
								continue;
							//해당 인접지역이 빙산이면 
							if(mp[yy][xx] != 0 && ch[yy][xx] == 0){
								ch[yy][xx] = group;
								q.push(make_pair(yy,xx));
							}
						}
					}
				}
			}
		}
		
		//두 덩어리 이상이면
		if(group >= 2)
			break; 
		
		//연도 1년추가  
		res++;
		//1년뒤 빙산 mp1에 저장 
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				int cnt = 0;
				if(mp[i][j] == 0)
					mp1[i][j] = 0;
				else{
					for(int k = 0; k < 4; k++){
						int yy = i + dy[k];
						int xx = j + dx[k];
						
						if(yy < 0 || xx < 0 || yy >= n || xx >= m)
							continue;
						//해당 인접지역이 바다이면 
						if(mp[yy][xx] == 0)
							cnt++;
					}
					if(cnt > mp[i][j])
						mp1[i][j] = 0;
					else
						mp1[i][j] = mp[i][j]-cnt;
				}
			}
		}
		//mp 갱신
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				mp[i][j] = mp1[i][j];
	}
	cout<<res;	
    return 0;
}
