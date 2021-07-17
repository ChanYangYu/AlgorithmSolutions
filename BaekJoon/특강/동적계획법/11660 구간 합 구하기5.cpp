#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
int sums[1025][1025];

int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","rt",stdin);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    
    cin>>n>>m;
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin>>sums[i][j];
			sums[i][j] += sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1];
	while(m--){
		int x1, y1, x2, y2;
		int res;
		
		cin>>y1>>x1>>y2>>x2;
		
		res = sums[y2][x2] - sums[y1-1][x2] - sums[y2][x1-1] + sums[y1-1][x1-1];
		cout<<res<<"\n";
	}
    return 0;
}
