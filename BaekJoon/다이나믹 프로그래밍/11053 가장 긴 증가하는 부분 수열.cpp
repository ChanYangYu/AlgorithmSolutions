#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int cache[1001];
int solve(int cur){
	int& ret = cache[cur];
	
	if(ret != -1)
		return ret;

	ret = 1;
	for(int i = cur+1; i < a.size(); i++)
		if(a[cur] < a[i])
			ret = max(ret, solve(i) + 1);
	
	return ret;
}
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	int n;
	
	cin>>n;
	
	for(int i = 0; i < n; i++){
		int x;
		
		cin>>x;
		a.push_back(x);
	}
	
	int res = 1;
	memset(cache, -1, sizeof(cache));
	for(int i = 0; i < n; i++)
		res = max(res, solve(i));
	
	cout<<res;
	return 0;
}
