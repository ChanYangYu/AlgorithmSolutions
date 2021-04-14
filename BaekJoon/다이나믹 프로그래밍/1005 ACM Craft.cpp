#include<bits/stdc++.h>
using namespace std;
int cache[1001];
int t[1001];
vector<int> mp[1001];
int n;

int solve(int pos){
	int& ret = cache[pos];
	
	if(ret != -1)
		return ret;
	
	ret = t[pos];
	//필요조건 탐색 
	for(int i = 0; i < mp[pos].size(); i++)
		//필요조건 중 최대시간으로 업데이트 
		ret = max(ret, solve(mp[pos][i]) + t[pos]);
	
	return ret;
}
int main(int argc, char** argv)
{
    cin.tie(0);
    //freopen("input.txt","rt",stdin);
    int test;
    
    cin>>test;
    
    for(int i = 0; i < test; i++){
    	int k;
    	
    	cin>>n>>k;
    	
    	for(int j = 1; j <= n; j++){
    		cin>>t[j];
    		mp[j].clear();
    	}
    	
    	memset(cache, -1, sizeof(cache));
    	for(int j = 0; j < k; j++){
    		int y;
    		int x;
    		
    		cin>>y>>x;
    		
    		//필요조건 벡터에 저장 
    		mp[x].push_back(y);
		}
		int start;
		
		cin>>start;
		cout<<solve(start)<<"\n";
	}
	
    return 0;
}
