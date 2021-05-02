#include <bits/stdc++.h>
using namespace std;
int cache[1<<16][16];
int adj[16][16];
int n;

int solve(int state, int pos, int start){
	int& ret = cache[state][pos];
    //�湮 üũ
	if(ret != -1)
		return ret;
    //��� ���� �湮�Ϸ�	
	if(state == ((1<<n)-1)){
        //ó�������� ���ư� �� �ִ°��
		if(adj[pos][start] != 0)
			return ret = adj[pos][start];
		//ó�� �������� ���ư� �� ���� ���
        else
			return ret = 987654321;
	}
	
	ret = 987654321;
    //���� �������� �ٸ� �������� �ִ� ��� Ž��
	for(int i = 0; i < n; i++){
		if(adj[pos][i] != 0 && (state & (1<<i)) == 0)
			ret = min(ret, solve((state | (1<<i)), i, start) + adj[pos][i]);
	}
	
	return ret;
}
int main(){   
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin>>adj[i][j];
	
	int res = 987654321;
	memset(cache, -1, sizeof(cache));
	res = min(res, solve(1, 0, 0));
	cout<<res;
    return 0;
}
