#include <bits/stdc++.h>
using namespace std;
int cache[1000001][2];
bool visited[1000001];
vector<vector<int> > v(1000001);
vector<vector<int> > child(1000001);

//tree 구조만들기 
void make_tree(int pos){
	visited[pos] = true;
	
	for(int i = 0; i < v[pos].size(); i++){
		int nxt = v[pos][i];
		
		if(!visited[nxt]){
			child[pos].push_back(nxt);
			make_tree(nxt);
		}
	}
		
}
int solve(int pos, int inc){
	int& ret = cache[pos][inc];
	
	if(ret != -1)
		return ret;
	
	//선택된 경우 
	if(inc){
		ret = 1;
		//선택하지 않거나 선택하거나 두경우 모두 탐색하여 최소값을 더한다. 
		for(int i = 0; i < child[pos].size(); i++)
			ret += min(solve(child[pos][i], 1),solve(child[pos][i], 0));
	}
	//선택되지 않은 경우 
	else{
		ret = 0;
 		
 		//선택되지 않았으므로 다음에는 무조건 선택이 되어야한다. 
		for(int i = 0; i < child[pos].size(); i++)
			ret += solve(child[pos][i], 1);
	}
	
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt","rt",stdin);
	int n;
	
	cin>>n;
	
	for(int i = 0; i < n-1; i++){
		int x, y;
		
		cin>>x>>y;
		
		v[x].push_back(y);
		v[y].push_back(x);
	}
	
	memset(cache, -1, sizeof(cache));
	make_tree(1);
	int res = min(solve(1,0), solve(1, 1));
	
	cout<<res;
	return 0;
}
