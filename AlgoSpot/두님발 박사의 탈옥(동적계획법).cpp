#include <bits/stdc++.h>
/* Ʋ������
 �ڿ������� Ž���ϴ� ������ �� ã������ ������ �߸� ����
 ���� �׸񿡼� ���� �׸����� �����Ǿ�� �ϹǷ� ������ ���� �������� ������ ��������Ѵ�.
 (������) <- (������)�� ��츦 ã�°��̹Ƿ� �����׿��� ���������� �� �� �ִ� ����� ���� �������Ѵ�. 
 
 //�ڵ� �κ� 
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
