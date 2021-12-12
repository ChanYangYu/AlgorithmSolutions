#include <bits/stdc++.h>
#define pii pair<int,int> 

/*
 1. 25명 중 7명을 선택하고 그 위치를 selected에 저장
 2. 7명을 다 선택한 후, 7명이 모두 연결되어있는지 bfs로 탐색(7개 중에서 맨하튼거리가 0인 점으로 탐색)
 3. 7명 모두 연결되었는지 확인되었으면 해당 경우의 수 ++
 
 틀린이유
  - int ch[7] = {0,}; 이부분을 초기화해주지 않아 AC가 나오지 않았다. 

*/
using namespace std;

char mp[5][5];
int ch[5][5];
vector<pii> selected;
int res;
int total;

bool check(){
	int ch[7] = {0,};
	int cnt = 0;
	queue<pii> q;
	
	q.push({selected[0].first, selected[0].second});
	ch[0] = 1;
	cnt++;
	
	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		
		q.pop();
		
		for(int i = 0; i < 7; i++){
			if(ch[i] == 1)
				continue;
			int yy = selected[i].first;
			int xx = selected[i].second;
			
			int manhatten = abs(y - yy) + abs(x - xx) -1;
			
			if(manhatten == 0){
				ch[i] = 1;
				cnt++;
				q.push({yy, xx});
			} 
		}
	}
	
	return cnt == 7;
}

void solve(int idx, int cnt, int scnt){
	if(cnt == 7){
		total++;
		if(scnt < 4)
			return;
		res += check() ? 1 : 0;
		return;
	}
	
	for(int i = idx; i < 25; i++){
		int y = i / 5;
		int x = i % 5;
		
		selected.push_back({y, x});
		
		if(mp[y][x] == 'S'){
			solve(i+1, cnt+1, scnt+1);
		}
		else{
			solve(i+1, cnt+1, scnt);
		}
		
		selected.pop_back();
	}
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  for(int i = 0; i < 5; i++){
  	for(int j = 0; j < 5; j++){
  		cin>>mp[i][j];
	}
  }
  
  solve(0, 0, 0);
  cout<<res;
  
}
