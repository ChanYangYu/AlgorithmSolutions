#include <bits/stdc++.h>
using namespace std;
int ch;
int cache[1000001];
int t;
int solve(int n){
	int& ret = cache[n];
	
	if(ret != -1)
		return ret;
		
	if(n == 1)
		return ret = 0;
	
	ret = 987654321;
	if(n % 3 == 0)
		ret = min(ret, solve(n / 3) + 1);
	if(n % 2 == 0)
		ret = min(ret, solve(n / 2) + 1);
	ret = min(ret, solve(n - 1) + 1);
	
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt","rt",stdin);
	int n;
	
	cin>>n;
	
	memset(cache, -1, sizeof(cache));
	int res = solve(n);
	cout<<res;
	return 0;
}
