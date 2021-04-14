#include<bits/stdc++.h>
using namespace std;
int cache[41][2];

void solve(int pos){
	int& zero = cache[pos][0];
	int& one = cache[pos][1];
	
	if(zero != -1 && one != -1)
		return;
	
	if(pos == 0){
		zero = 1;
		one = 0;
		return;
	}
	else if(pos == 1){
		zero = 0;
		one = 1;
		return;
	}
	
	//n-1, n-2 수에서의 0,1개수 각각 계산 
	solve(pos-1);
	solve(pos-2);
	
	//계산된 0, 1의 개수 합 계산 
	zero = cache[pos-1][0] + cache[pos-2][0];
	one = cache[pos-1][1] + cache[pos-2][1];
	
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
    	
    	solve(n);
    	
    	cout<<cache[n][0]<<" "<<cache[n][1]<<"\n";
	}
    return 0;
}
