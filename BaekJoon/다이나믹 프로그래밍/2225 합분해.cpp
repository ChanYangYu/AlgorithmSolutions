#include<bits/stdc++.h>
using namespace std;
int n, k;
int cache[201][201];

int solve(int cur, int cnt){
	if(cur > n)
		return 0;
	if(cnt > k)
		return 0;
		
	int& ret = cache[cur][cnt];
	if(ret != -1)
		return ret;
	//답인 경우 
	if(cnt == k && cur == n)
		return ret = 1;
	//답이 될 수 없는 경우 
	
	ret = 0;
	for(int i = 0; i <= n; i++){
		ret += solve(cur + i, cnt + 1);
		ret = ret %1000000000;
	}
	
	return ret;
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt","rt",stdin);
	
	cin>>n>>k;
	
	int res = 0;
	memset(cache, -1, sizeof(cache));
	cout<<solve(0, 0);
	return 0;
}
