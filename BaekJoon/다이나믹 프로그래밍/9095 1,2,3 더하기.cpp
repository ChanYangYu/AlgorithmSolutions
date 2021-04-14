#include<bits/stdc++.h>
using namespace std;
int cache[12];

int solve(int pos){
	if(pos == 0)
		return 1;
	
	int& ret = cache[pos];
	
	if(ret != -1)
		return ret;
	
	ret = 0;
	//1 ~ 3 더하는 경우 탐색 
	for(int i = 1; i <= 3; i++){
		if(pos - i >= 0)
			ret += solve(pos - i);
	}
	
	return ret;
} 
int main(int argc, char** argv)
{
    cin.tie(0);
    //freopen("input.txt","rt",stdin);
    int t;
    
    cin>>t;
    
    memset(cache, -1, sizeof(cache));
    for(int i = 0; i < t; i++){
    	int n;
    	
    	cin>>n;
    	
    	cout<<solve(n)<<"\n";
	}
    return 0;
}
