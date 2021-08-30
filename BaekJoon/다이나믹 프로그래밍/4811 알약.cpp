#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

ll cache[61][31][31];
ll solve(int n, int w, int h){
	ll& ret = cache[n][w][h];
	
	if(ret != -1)
		return ret;
	if(w == 0)
		return ret = 1;
	if(h == 0)
		return ret = solve(n+1, w-1, h+1);
	else
		return ret = solve(n+1, w-1, h+1) + solve(n+1, w, h-1);
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    while(true){
		int w;	
    	cin>>w;
    	
    	if(w == 0)
    		break;
    	memset(cache, -1, sizeof(cache));
		cout<<solve(0, w, 0)<<"\n";
	}
    return 0;
}
