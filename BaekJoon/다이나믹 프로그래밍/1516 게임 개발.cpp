#include <bits/stdc++.h>
using namespace std;
vector<int> parents[501];
int create_time[501];
int cache[501];

//�ش� �ǹ��� ����µ� �ɸ��� �ּ� �ð� 
int solve(int pos){
	int& ret = cache[pos];
	
	if(ret != -1)
		return ret;
	
	ret = create_time[pos];
	for(int i = 0; i < parents[pos].size(); i++)
		ret = max(ret, solve(parents[pos][i]) + create_time[pos]);
	
	return ret;
}
int main(void){
	//ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	int n;
	
	cin>>n;
	
	for(int i = 1; i <= n; i++){
		int p;
		cin>>create_time[i];
		cin>>p;
		
		while(p != -1){
			parents[i].push_back(p);
			cin>>p;
		}
	}
	
	memset(cache, -1, sizeof(cache));
	
	//������ ���꿡 �ɸ��� �ð� ��� 
	for(int j = 1; j <= n; j++)
		cout<<solve(j)<<"\n";
	
    return 0;
}
