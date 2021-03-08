#include <bits/stdc++.h>
/* 틀린이유
 뒤에서부터 탐색하는 로직은 잘 찾았으나 방향을 잘못 설정
 이전 항목에서 다음 항목으로 선정되어야 하므로 다음과 같이 이전항의 개수로 나눠줘야한다.
 (현재항) <- (이전항)의 경우를 찾는것이므로 이전항에서 현재항으로 갈 수 있는 경우의 수로 나눠야한다. 
 
 //코드 부분 
 (solve(d-1, adj[pos][i])) / adj[pos].size(); 
 -> (solve(d-1, adj[pos][i])) / adj[next].size();
*/ 
  

using namespace std;
vector<vector<int> > adj;
int start;
double cache[101][51];
int check[101][51];

double solve(int d, int pos){
	int& ch = check[d][pos];
	double& ret = cache[d][pos];
	
	if(ch != -1)
		return ret;
	
	ch = 1;
	if(d == 0){
		if(pos == start)
			return ret = 1.0;
		else
			return ret = 0.0;
	}
						
	ret = 0.0;
	for(int i = 0; i < adj[pos].size(); i++){
		int next = adj[pos][i];
		ret += (solve(d-1, adj[pos][i])) / adj[next].size();
	}
	return ret;
}
  
int main(void)
{
	//ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt", stdin);
	cin.tie(0);
	int t, n, d;
	
	cin>>t;
	for(int k = 0; k < t; k++){
		cin>>n>>d>>start;
		
		memset(check, -1, sizeof(check));
		memset(cache, 0, sizeof(cache));
		adj.clear();
		for(int i = 0; i < n; i++){
			vector<int> tmp;
			for(int j = 0; j < n; j++){
				int x;
				cin>>x;
				if(x)
					tmp.push_back(j);
			}
			adj.push_back(tmp);
		}
		
		int T;
		cin>>T;
		
		for(int i = 0; i < T; i++){
			int tmp;
			cin>>tmp;
			
			double res = solve(d, tmp);
			printf("%.8lf ",res);
		}
		printf("\n");
		
	}
	return 0;
}
