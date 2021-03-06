#include <bits/stdc++.h>

using namespace std;
int cache[101][101][101];
/* 틀린코드 cache[101][101] <- cache[d][r]
 반례 d = 2, r = 1, n = 2 과 d = 2, r = 1, n = 1이 다른 경우이지만
 같은 cache[d][r]을 공유하게되어 잘못 참조한다.
 따라서 3차원 배열인 cache[d][r][n]을 사용하여야 한다.
*/ 
int solve(int d, int r, int n){
	int& ret = cache[d][r][n];
	
	if(ret != -1)
		return ret;
	
	if(r == 0)
		return ret = 1;
	
	ret = 0;
	
	for(int i = 1; i <= r; i++){
		if(d != 0)
			ret += (solve(d+1, r - i, i) * (n + i - 1)) % 10000000;
		else
			ret += (solve(d+1, r - i, i)) % 10000000;
	}
	
	//오버플로우 연산처리!
	//틀린 코드 return ret % 10000000;
	//위와 같은 코드는 ret에 저장되지 않는다! 
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
		int res = solve(0, n, 0);
		
		cout<<res<<"\n";
	}
	return 0;
}
