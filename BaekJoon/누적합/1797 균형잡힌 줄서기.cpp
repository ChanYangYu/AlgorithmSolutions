#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int sum;
int res;
int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	unordered_map<int, int> mp;
    int n;
    vector<pii> pos;
    
    cin>>n;
    
    for(int i = 0; i < n; i++){
    	int s, x;
    	cin>>s>>x;
    	
    	pos.push_back({x,s});
	}
	
	sort(pos.begin(), pos.end());
	
    for(int i = 0; i < n; i++){
    	int s = pos[i].second;
    	int x = pos[i].first;
    	
    	if(s == 0)
    		sum += 1;
    	else
    		sum -= 1;
    	
    	if(mp[sum] != 0)
    		res = max(res, pos[i].first - pos[mp[sum]].first);
    	else if(sum == 0)
    		res = max(res, pos[i].first - pos[0].first);
		else
    		mp[sum] = i+1;
	}
	
	cout<<res;
    return 0;
}
