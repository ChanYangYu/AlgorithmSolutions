#include <bits/stdc++.h>
#define ll long long
using namespace std;
int cache[101][10][1024];
int n;

int solve(int idx, int num, int state){
	if(idx == n){
		if(state == (1<<10)-1)
			return 1;
		return 0;
	}
	int& ret = cache[idx][num][state];
	
	if(ret != -1)
		return ret % 1000000000;
	
	ret = 0;
	if(num-1 >= 0)
		ret += solve(idx+1, num-1, (state | (1<<(num-1))));
	if(num+1 <= 9)
		ret += solve(idx+1, num+1, (state | (1<<(num+1))));
	
	return ret % 1000000000;
}
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	
	int res = 0;
	int state = 0;
	for(int i = 1; i <= 9; i++){
		memset(cache, -1, sizeof(cache));
		res += solve(1, i, (state | (1<<i)));
		res = res % 1000000000;
		
	}
	
	cout<<res<<"\n";
	return 0;
}


