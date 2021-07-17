#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
int sum[100001];

int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","rt",stdin);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    
    cin>>n>>m;
    
    for(int i = 1; i <= n; i++){
    	cin>>sum[i];
    	sum[i] += sum[i-1];
	}
	
	while(m--){
		int a, b;
		
		cin>>a>>b;
		
		cout<<sum[b] - sum[a-1]<<"\n";
	}
   	return 0;
}
