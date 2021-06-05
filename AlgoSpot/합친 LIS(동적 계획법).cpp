#include <bits/stdc++.h>
using namespace std;
vector<int> a, b;
int cache[101][101];

int solve(int i, int j, int prev){
	int& ret = cache[i][j];
	
	if(ret != -1)
		return ret;
	
	ret = 1;
	
	//첫번째 배열 탐색 
	for(int k = i; k < a.size(); k++){
		if(a[k] > prev)
			ret = max(ret, solve(k+1, j, a[k]) + 1);
	}
	
	//두번째 배열 탐색 
	for(int k = j; k < b.size(); k++){
		if(b[k] > prev)
			ret = max(ret, solve(i, k+1, b[k]) + 1);
	}
	return ret;
	
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	cin.tie(0);
	int t;
	
	cin>>t;
	for(int l = 0; l < t; l++){
		int n, m;
		cin>>n>>m;
		
		//입력 
		for(int k = 0; k < n; k++){
			int x;
			cin>>x;
			a.push_back(x);
		}
		
		for(int k = 0; k < m; k++){
			int x;
			cin>>x;
			b.push_back(x);
		}
		
		//초기화 
		memset(cache, -1, sizeof(cache));
		
		int res = 0;
		
		//시작위치 선정 (1,0) (2,0) (3,0) ...
		for(int i = 0; i < a.size(); i++)
			res = max(res, solve(i+1, 0, a[i]));
		//시작위치 선정 (0,1) (0,2) (0,3) ... 
		for(int i = 0; i < b.size(); i++)
			res = max(res, solve(0, i+1, b[i]));
		cout<<res<<"\n";
		a.clear();
		b.clear();
	}
	return 0;
} 
