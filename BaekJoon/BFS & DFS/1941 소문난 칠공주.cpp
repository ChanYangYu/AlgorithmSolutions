#include <bits/stdc++.h>
#define pii pair<int,int> 

/*
 1. 25�� �� 7���� �����ϰ� �� ��ġ�� selected�� ����
 2. 7���� �� ������ ��, 7���� ��� ����Ǿ��ִ��� bfs�� Ž��(7�� �߿��� ����ư�Ÿ��� 0�� ������ Ž��)
 3. 7�� ��� ����Ǿ����� Ȯ�εǾ����� �ش� ����� �� ++
 
 Ʋ������
  - int ch[7] = {0,}; �̺κ��� �ʱ�ȭ������ �ʾ� AC�� ������ �ʾҴ�. 

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
