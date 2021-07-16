#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
int mp[501][501];

int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","rt",stdin);
    cin.tie(0);
    cout.tie(0);
    
	int n;
	
	cin>>n;
	
	cin>>mp[1][1];
	
	int res = 0;
	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= i; j++){
			cin>>mp[i][j];
			mp[i][j] += max(mp[i-1][j-1], mp[i-1][j]);
			res = max(res, mp[i][j]);
		}
	}
	
	cout<<res;
   	return 0;
}
