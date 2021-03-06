#include <bits/stdc++.h>
/* 풀이 전략
 1. 먼저 전체의 경우의 수를 구하는 solve함수 구현
 2. n이 홀수 인 경우의 대칭되는 경우의 수 제거
 3. n이 짝수 인 경우의 대칭되는 경우의 수 제거
*/ 
using namespace std;
int cache[101];
int n;

int solve(int pos){
	int& ret = cache[pos];
	int mid = n / 2;
	int isOdd = n % 2;
	
	if(ret != -1)
		return ret;
	
	//홀수인 경우 대칭되는 경우는 중간값에 오는 타일이 반드시 1일때이다. 
	if(isOdd && pos == mid)
		ret = -1;
	else	
		ret = 0;
	
	if(pos == n)
		return ret = 1;
		
	//짝수인 경우 대칭되는 경우는 다음 배치되는 타일이 중간값을 지나는 경우이다. 
	if(pos + 1 <= n){ 
		if(!isOdd && pos + 1 == mid)
			ret -= 1;
		ret += solve(pos+1);
	}
	if(pos + 2 <= n){
		if(!isOdd && (pos < mid && pos + 2 >= mid))
			ret -= 1;
		ret += solve(pos+2);
	}
	
	ret %= 1000000007;
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt", stdin);
	cin.tie(0);
	int t;
	
	cin>>t;
	
	for(int k = 0; k < t; k++){
		cin>>n;
		
		memset(cache, -1, sizeof(cache));
		int res = solve(0);
		
		cout<<res<<"\n";
	}
	return 0;
}
