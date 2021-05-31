#include <bits/stdc++.h>
#define ll long long
using namespace std;
int mp[501][501];

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	int n, m, b;
		
	cin>>n>>m>>b;
	
	int mx = -1;
	int mn = 257;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin>>mp[i][j];
			mx = max(mx, mp[i][j]);
			mn = min(mn, mp[i][j]);
		}
	}
	int res = 987654321;
	int h = -1;
	
	for(int k = mn; k <= mx; k++){
		int remain = b;
		int time = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(mp[i][j] == k)
					continue;
				else if(mp[i][j] < k){
					int diff = k - mp[i][j];
					time += diff;
					remain -= diff;
				}
				else{
					int diff = mp[i][j] - k;
					time += 2*diff;
					remain += diff;
				}
			}
		}
		if(remain < 0)
			continue;
		if(time <= res){
			res = time;
			h = k;
		}
	}
	
	cout<<res<<" "<<h;
	return 0;
}
