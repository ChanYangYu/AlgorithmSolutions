#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

ll cache[21][101];
int n;
vector<int> nums;

ll solve(int cur, int idx){
	if(cur < 0 || cur > 20)
		return 0;
	
	if(idx == n-1){
		if(cur == nums[idx])
			return 1;
		else
			return 0;
	}
	ll& ret = cache[cur][idx];
	
	if(ret != -1)
		return ret;
	
	ret = solve(cur+nums[idx], idx+1) + solve(cur-nums[idx], idx+1);
	return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "rt",stdin);
	cin.tie(0);
    cout.tie(0);
	
	cin>>n;
	
	for(int i = 0; i < n; i++){
		int x;
		
		cin>>x;
		nums.push_back(x);
	}
	
	memset(cache, -1, sizeof(cache));
	cout<<solve(nums[0], 1);
	return 0;
}
