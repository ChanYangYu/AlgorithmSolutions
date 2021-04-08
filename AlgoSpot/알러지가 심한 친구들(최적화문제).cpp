#include <bits/stdc++.h>
using namespace std;
int res;
vector<int> caneat[51];
vector<int> food[51];
int check[51];
int n, m;

void solve(int cnt, int idx){
	
	if(cnt >= res)
		return;
	
	int first = -1;
	for(int i = 0; i < n; i++){
		if(check[i] == 0){
			first = i;
			break;
		}
	}
	
	if(first == -1){
		res = min(res, cnt);
		return;
	}
	
	for(int i = 0; i < caneat[first].size(); i++){
		//먹을 수 있는 음식 선택 
		int f = caneat[first][i];
		
		//해당 음식으로 커버 
		for(int j = 0; j < food[f].size(); j++){
			int s = food[f][j];
			check[s] += 1;
		}
		
		//탐색 
		solve(cnt+1, idx+1);
		
		//음식 롤백 
		for(int j = 0; j < food[f].size(); j++){
			int s = food[f][j];
			check[s] -= 1;
		}
	}
}


int main() {
	cin.tie(0);
	//freopen("input.txt", "rt", stdin);
	int t;
	
	cin>>t;
	
	for(int k = 0; k < t; k++){
		unordered_map<string, int> str_to_int;
		string str;
		
		cin>>n>>m;
		int idx = 0;
		for(int i = 0; i < n; i++){
			cin>>str;
			
			str_to_int[str] = idx;
			idx++;
			caneat[i].clear();
		}
		
		//각 음식마다 커버할 수 있는 사람들을 구함 
		for(int i = 0; i < m; i++){
			int c;
			cin>>c;
			
			food[i].clear();
			for(int j = 0; j < c; j++){
				cin>>str;
				
				idx = str_to_int[str];
				
				caneat[idx].push_back(i);
				food[i].push_back(idx);
			}
		}
		memset(check, 0, sizeof(check));
		res = INT_MAX;
		solve(0,0);
		cout<<res<<"\n";
	}
	return 0;
}
