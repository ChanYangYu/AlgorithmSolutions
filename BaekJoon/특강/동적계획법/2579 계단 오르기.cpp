#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
int stair[301];
int cache[301][3];
int n;

int solve(int cur, int cnt){
	if(cur == n)
		return stair[cur];
	
	int& ret = cache[cur][cnt];
	
	if(ret != -1)
		return ret;
	
	ret = 0;
	
	if(cur+1 <= n && cnt < 2)
		ret = max(ret, solve(cur+1, cnt+1) + stair[cur]);
	if(cur+2 <= n)
		ret = max(ret, solve(cur+2, 1) + stair[cur]);
	
	return ret;
	
}

int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","rt",stdin);
    cin.tie(0);
    cout.tie(0);
    
    
    cin>>n;
    
    for(int i = 1; i <= n; i++)
    	cin>>stair[i];
    
    memset(cache, -1, sizeof(cache));
    cout<<solve(0,0);
    
   	return 0;
}
