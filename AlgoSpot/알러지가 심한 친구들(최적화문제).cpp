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
		//���� �� �ִ� ���� ���� 
		int f = caneat[first][i];
		
		//�ش� �������� Ŀ�� 
		for(int j = 0; j < food[f].size(); j++){
			int s = food[f][j];
			check[s] += 1;
		}
		
		//Ž�� 
		solve(cnt+1, idx+1);
		
		//���� �ѹ� 
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
		
		//�� ���ĸ��� Ŀ���� �� �ִ� ������� ���� 
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
