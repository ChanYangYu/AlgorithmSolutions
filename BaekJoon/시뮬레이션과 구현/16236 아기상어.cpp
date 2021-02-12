#include <bits/stdc++.h>
using namespace std;
int mp[20][20];
int ch[20][20];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int main(void){
	ios_base::sync_with_stdio(false);
	queue<pair<pair<int, int>, int> > q;
	int sy,sx;
	int size = 2;
	int ate = 0;
	int fish = 0;
	int time = 0;
	int n;
	
	cin>>n;
	
	//맵 입력 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin>>mp[i][j];
			
			//상어위치이면 
			if(mp[i][j] == 9){
				sy = i;
				sx = j;
				//상어위치 0으로 초기화 
				mp[i][j] = 0;
			}
			else if(mp[i][j] != 0)
				fish++;
		}
	}
	
	while(1){
		//물고기 개수가 0이면 종료 
		if(fish == 0)
			break;
		//ch초기화 
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				ch[i][j] = 0;
		
		q.push({{sy,sx},0});
		//최소거리 물고기 위치 및 이동시간 
		int fy = -1, fx = -1;
		int mcount = 987654321;
		while(!q.empty()){
			int y = q.front().first.first;
			int x = q.front().first.second;
			int c = q.front().second;
			
			q.pop();
			//상어보다 작은 물고기위치이고 최소 거리인경우 
			if(mp[y][x] > 0 && mp[y][x] < size && mcount >= c){
				//최소거리에 있는 경우 
				if(mcount > c){
					fy = y;
					fx = x;
					mcount = c;	
				}
				//거리가 같고 더 위에 있는경우 
				else if(fy >= y){
					if(fy > y){
						fy = y;
						fx = x;
					}
					//같은 높이에 있고 더 왼쪽에 있는경우 
					else if(fx > x){
						fy = y;
						fx = x;
					}
				}
				continue;
			} 
			
			//네 방향 탐색! 
			for(int i = 0; i < 4; i++){
				int yy = dy[i] + y;
				int xx = dx[i] + x;
				
				if(yy < 0 || yy >= n || xx < 0 || xx >= n)
					continue;
				
				//처음 방문하고 상어의 사이즈보다 작으면 
				if(ch[yy][xx] == 0 && mp[yy][xx] <= size){
					ch[yy][xx] = 1;
					q.push({{yy,xx},c+1});
				}
			}
		} 
		
		//못찾은 경우 
		if(fx == -1 && fy == -1)
			break;
		else{
			//물고기 먹음 
			ate++;
			//시간추가 
			time += mcount;
			//먹은량이 사이즈와 같으면 
			if(ate == size){
				//사이즈업 
				size++;
				ate = 0;
			}
			//해당위치 제거 
			mp[fy][fx] = 0;
			//물고기 숫자-- 
			fish--;
			
			//상어위치 변경 
			sy = fy;
			sx = fx;
		}
	}
	
	//결과 출력 
	cout<<time;
	

    return 0;
}
