#include <bits/stdc++.h>

using namespace std;
int cache[101][101];
int solve(int r, int n){
	int& ret = cache[r][n];
	
	if(ret != -1)
		return ret;
	
	if(r == 0)
		return ret = 1;
	
	ret = 0;
	
	//0일때 n번 실행시키므로 전체 시간복잡도는 O(N^2 *N) = O(N^3) 
	for(int i = 1; i <= r; i++){
		if(n != 0)
			ret += (solve(r - i, i) * (n + i - 1)) % 10000000;
		else
			ret += (solve(r - i, i)) % 10000000;
	}
	
	ret %= 10000000;
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt", stdin);
	cin.tie(0);
	int t;
	int n;
	
	cin>>t;
	
	for(int k = 0; k < t; k++){
		cin>>n;
		
		memset(cache, -1, sizeof(cache));
		int res = solve(n, 0);
		
		cout<<res<<"\n";
	}
	return 0;
}
