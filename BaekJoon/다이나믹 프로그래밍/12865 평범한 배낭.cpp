#include <bits/stdc++.h>
using namespace std;
int cache[100001][101];
int weight[101];
int value[101];
int n, k;

int solve(int cur, int idx){
	int& ret = cache[cur][idx];
	
	//이미 답이 있는 경우 
	if(ret != -1)
		return ret;
	
	//모든 물건 검토한 경우 
	if(idx == n)
		return ret = 0;

	ret = 0;
	
	//무게 초과하지않으면 챙기는 경우 검토 
	if(cur + weight[idx] <= k)
		ret = max(ret, solve(cur + weight[idx], idx +1) + value[idx]);
	//챙기지 않는 경우 검토 
	ret = max(ret, solve(cur, idx + 1));
	
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt","rt",stdin);
	
	cin>>n>>k;
	
	for(int i = 0; i < n; i++)
		cin>>weight[i]>>value[i];
	
	memset(cache, -1, sizeof(cache));
	
	int res = solve(0, 0);
	
	cout<<res;
	return 0;
}
