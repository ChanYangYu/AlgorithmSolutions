#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>

using namespace std;

int cache[1001][1001];
int card[1001];

int solve(int s, int e, int t){
	if(s > e)
		return 0;
	int& ret = cache[s][e];
	
	if(ret != -1)
		return ret;
	
	if(t == 0){
		ret = max(card[s] + solve(s+1, e, 1), card[e] + solve(s, e-1, 1));
		return ret;
	}
	else{
		ret = min(solve(s+1, e, 0), solve(s, e-1, 0));
		return ret;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int test;
	
	cin>>test;
	
	for(int i = 1; i <= test; i++){
		int n;
		
		cin>>n;
		
		memset(cache, -1, sizeof(cache));
		for(int j = 0; j < n; j++)
			cin>>card[j];
		cout<<solve(0, n-1, 0)<<"\n";
	}
    return 0;
}
