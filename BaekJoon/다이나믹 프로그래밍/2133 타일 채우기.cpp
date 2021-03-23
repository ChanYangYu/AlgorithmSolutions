#include <bits/stdc++.h>
using namespace std;
int cache[31][16][3];
int n;

int solve(int pos, int jmp, int cases){
	int& ret = cache[pos][jmp][cases];
	
	//이미 구한 경우 
	if(ret != -1)
		return ret;
	
	//다 채운경우 
	if(pos == n)
		return ret = 1;
	
	ret = 0;
	//2 ~ 30을 채우는 타일의 경우 탐색 
	for(int i = 1; i <= 15; i++){
		//타일을 채울 수 있는 경우 
		if(pos + (2*i) <= n){
			//위, 아래 바뀐 두가지 경우 탐색 
			ret += solve(pos + (2*i), i, 0);
			ret += solve(pos + (2*i), i, 1);
			//크기가 2인 경우는 2*1 3개 인경우 체크 
			if(i == 1)
				ret += solve(pos + (2*i), i, 2);
		}
		else
			break;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	
	cin>>n;
	memset(cache, -1, sizeof(cache));
	int res = solve(0, 0, 0);
	
	cout<<res;
	return 0;
}
