#include<bits/stdc++.h>
using namespace std;
int n;
int cache[1001];
int solve(int pos){
	int& ret = cache[pos];
	
	if(ret != -1)
		return ret;
	
	//기저사례 
	if(pos == n)
		return ret = 1;
	
	//2x1 타일 
	ret = solve(pos+1) % 10007;
	
	//2x1 타일, 2x2타일 
	if(pos + 2 <= n)
		ret += (2 * solve(pos+2)) % 10007;
	
	return ret % 10007;
}

int main(int argc, char** argv)
{
    cin.tie(0);
    //freopen("input.txt","rt",stdin);
    
    cin>>n;
    
    memset(cache, -1, sizeof(cache));
    
    cout<<solve(0);
    return 0;
}
