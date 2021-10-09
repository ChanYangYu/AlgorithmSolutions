#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
int cache[4001][4001][2];
string A;
string B;

int solve(int a, int b, int c){
	if(a == A.size() || b == B.size())
		return 0;
	int& ret = cache[a][b][c];
	
	if(ret != -1)
		return ret;
	
	if(c == 1){
		if(A[a] == B[b])
			return ret = solve(a+1, b+1, 1) +1;
		else
			return ret = 0;
	}
	else{
		ret = 0;
		if(A[a] == B[b])
			ret = max(ret, solve(a+1,b+1,1) + 1);
		ret = max(ret, solve(a+1, b, 0));
		ret = max(ret, solve(a, b+1, 0));
	}
	return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","rt",stdin);
    cin.tie(0);
    cout.tie(0);

	cin>>A>>B;
	
	memset(cache, -1, sizeof(cache));
	
	cout<<solve(0,0,0)<<"\n";
	
	
    return 0;
}
