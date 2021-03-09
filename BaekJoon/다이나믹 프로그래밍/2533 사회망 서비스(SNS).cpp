#include <bits/stdc++.h>
using namespace std;
int cache[1000001][2];
bool visited[1000001];
vector<vector<int> > v(1000001);
vector<vector<int> > child(1000001);

//tree ��������� 
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
	
	//���õ� ��� 
	if(inc){
		ret = 1;
		//�������� �ʰų� �����ϰų� �ΰ�� ��� Ž���Ͽ� �ּҰ��� ���Ѵ�. 
		for(int i = 0; i < child[pos].size(); i++)
			ret += min(solve(child[pos][i], 1),solve(child[pos][i], 0));
	}
	//���õ��� ���� ��� 
	else{
		ret = 0;
 		
 		//���õ��� �ʾ����Ƿ� �������� ������ ������ �Ǿ���Ѵ�. 
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
