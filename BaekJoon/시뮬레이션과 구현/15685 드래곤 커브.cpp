#include <bits/stdc++.h>
using namespace std;
int dy[4] = {0,-1,0,1};
int dx[4] = {1,0,-1,0};
int mark[101][101];
vector<int> dragon;
int g;

//다음 방향으로 변경 
int turn(int d){
	switch(d){
		case 0 : return 1;
		case 1 : return 2;
		case 2 : return 3;
		case 3 : return 0;
	}
}

//드래곤 커브 생성 
void make_dragon(int y, int x, int cur){
	if(g == cur)
		return;
	int start = dragon.size() - 1;
	for(int i = start; i >= 0; i--){
		int t = turn(dragon[i]);
		y = y + dy[t];
		x = x + dx[t];
		
		//범위값인 경우 
		if(y >= 0 && y <=100 && x >= 0 && x <= 100)
			/*오답노트 : y, x값 이미 조정 후 또 한번 조정한값을 넣었음(코드 로직 수정시 체크x) 
			  코드 수정 시 해당 로직에 연관된 값들을 다시한번 체크해볼것 
			*/
			mark[y][x] = 1;
		dragon.push_back(t);
	}
	make_dragon(y, x, cur+1);
}

int main() {
	cin.tie(0);
	//freopen("input.txt", "rt", stdin);
	int n;
	
	cin>>n;
	
	//모든 드래곤 커브 좌표 탐색 
	for(int i = 0; i < n; i++){
		int x, y, d;
		
		cin>>x>>y>>d>>g;
		
		mark[y][x] = 1;
		mark[y + dy[d]][x + dx[d]] = 1;
		
		dragon.clear();
		dragon.push_back(d);
		make_dragon(y + dy[d], x + dx[d], 0);
	
	}
	
	int cnt = 0;
	for(int i = 0; i <= 100; i++){
		for(int j = 0; j <= 100; j++){
			if(i + 1 > 100 || j + 1 > 100)
				break;
			//크기가 1인 사각형 체크 
			if(mark[i][j] == 1){
				if(mark[i+1][j] == 0)
					continue;
				if(mark[i][j+1] == 0)
					continue;
				if(mark[i+1][j+1] == 0)
					continue;
				cnt++;
			}
		}
	}
	
	cout<<cnt;
	return 0;
}
