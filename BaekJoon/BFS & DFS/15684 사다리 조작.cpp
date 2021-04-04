#include <bits/stdc++.h>
using namespace std;
int mp[31][11][2];
int n, m, h;
vector<pair<int, int> > possible;

//답 체크 함수 
bool check(){
	for(int k = 1; k <= n; k++){
		int i = 1;
		int j = k;
		while(i <= h){
			if(mp[i][j][0] == 1){
				j--;
				i++;
			}
			else if(mp[i][j][1] == 1){
				j++;
				i++;
			}
			else
				i++;
		}
		if(k != j)
			return false;
	}
	return true;
}

bool solve(int choice, int cnt, int start){
	//기저사례 
	if(choice == cnt){
		if(check())
			return true;
		else
			return false;
	}
	else{
		//다음 선 선택 
		for(int s = start;  s < possible.size(); s++){
			int i = possible[s].first;
			int j = possible[s].second;
			
			//겹치지 않는 선인 경우 
			if(mp[i][j][0] == 0 && mp[i][j][1] == 0 && mp[i][j+1][1] == 0){
				mp[i][j][1] = 1;
				mp[i][j+1][0] = 1;
				
				//답을 찾았으면 종료 
				if(solve(choice, cnt+1, s+1))
					return true;
				mp[i][j][1] = 0;
				mp[i][j+1][0] = 0;
			}
		}
	}
	return false;
}
int main() {
	cin.tie(0);
	//freopen("input.txt", "rt", stdin);
	
	cin>>n>>m>>h;
	
	//mp에 표기 
	for(int i = 0; i < m; i++){
		int a, b;
		
		cin>>a>>b;
		
		mp[a][b][1] = 1;
		if(b+1 <= n)
			mp[a][b+1][0] = 1;
	}
	
	//가능한 위치 탐색 
	for(int i = 1; i <= h; i++){
		for(int j = 1; j < n; j++){
			if(mp[i][j][0] == 0 && mp[i][j][1] == 0 && mp[i][j+1][1] == 0)
				possible.push_back({i, j});
		}
	}
	
	//0 ~ 3번 추가했을때 답이 있는지 체크 
	for(int i = 0; i <= 3; i++){
		if(solve(i, 0, 0)){
			cout<<i;
			return 0;
		}
	}
	
	//없으면 -1출력 
	cout<<"-1";
	return 0;
}
