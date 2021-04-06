#include <bits/stdc++.h>
using namespace std;
int num[101];
long long cache[101][21];
int n;

long long solve(int pos, int res){
	long long& ret = cache[pos][res];
	
	if(ret != -1)
		return ret;
	
	if(pos == n-1){
		if(res == num[pos])
			return ret = 1;
		else
			return ret = 0;
	}
	
	ret = 0;
	if(res + num[pos] <= 20)
		ret += solve(pos+1, res + num[pos]);
	if(res - num[pos] >= 0)
		ret += solve(pos+1, res - num[pos]);

	return ret;
	
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt", stdin);
	cin.tie(0);
	
	cin>>n;
	for(int i = 0; i < n; i++)
		cin>>num[i];
	
	memset(cache, -1, sizeof(cache));
	long long res = solve(1, num[0]);
	
	cout<<res;
	
	
	return 0;
}
