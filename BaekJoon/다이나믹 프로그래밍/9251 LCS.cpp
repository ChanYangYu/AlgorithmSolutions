#include <bits/stdc++.h>
#define MAX 15
using namespace std;
int cache[1001][1001];
string A, B;

int solve(int a, int b){
	//기저 사례 
	if(a >= A.size() || b >= B.size())
		return 0;
	
	int& ret = cache[a][b];
	if(ret != -1)
		return ret;
	
	//선택
	int target = A[a];
	
	ret = 0;
	for(int i = b; i < B.size(); i++)
		if(target == B[i])
			ret = max(ret, solve(a+1, i+1) + 1);
	
	ret = max(ret, solve(a+1, b));
	
	return ret;
}
int main() {
	cin.tie(0);
	//freopen("input.txt", "rt", stdin);
	
	cin>>A>>B;
	
	memset(cache, -1, sizeof(cache));
	int ret = solve(0, 0);
	
	cout<<ret;
	return 0;
}
