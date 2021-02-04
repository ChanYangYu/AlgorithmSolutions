#include <bits/stdc++.h>
using namespace std;
int ch[300][300];
int dy[8] = {-1,-2,-2,-1, 1, 2, 1, 2};
int dx[8] = {-2,-1, 1, 2, 2, 1,-2,-1};

int main(void){
	ios_base::sync_with_stdio(false);
	int t;
	
	cin>>t;
	
	//test케이스 반복 
	for(int k = 0; k < t; k++){
		int size;
		cin>>size;
		
		//방문여부 검사 배열 초기화 
		for(int i = 0; i < size; i++)
			for(int j = 0; j < size; j++)
				ch[i][j] = 0;
		//현재 위치 입력 
		int y,x,ty,tx;
		cin>>y>>x;
		//목표 위치 입력 
		cin>>ty>>tx;
		
		queue<pair<pair<int, int>,int > > q;
		
		//시작위치 큐에 삽입 
		q.push({{y,x},0});
		
		//시작점 방문처리 
		ch[y][x] = 0;
		while(!q.empty()){
			y = q.front().first.first;
			x = q.front().first.second;
			int c = q.front().second;
			
			q.pop();
			
			//목표지점에 도착했으면 
			if(y == ty && x == tx){
				//결과값 출력후 종료 
				cout<<c<<endl;
				break;
			}
			
			//방향 탐색 
			for(int i = 0; i < 8; i++){
				int yy = dy[i] + y;
				int xx = dx[i] + x;
				
				//범위 조사 
				if(yy < 0 || yy >= size || xx < 0 || xx >= size)
					continue;
				//처음방문이면 큐에 삽입 
				if(ch[yy][xx] == 0){
					ch[yy][xx] = 1;
					q.push({{yy,xx},c+1});
				}
			}
		}
	}
	
    return 0;
}
