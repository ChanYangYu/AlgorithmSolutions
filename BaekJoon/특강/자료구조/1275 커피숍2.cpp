#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

ll tr[1<<18];

ll seg_sum(int node, int s, int e, int l, int r){
	if(e < l || s > r)
		return 0;
	if(l <= s && e <= r)
		return tr[node];
	else
		return seg_sum(2*node, s, (s+e)/2, l, r) + seg_sum(2*node+1, (s+e)/2+1, e, l, r);
}

void update(int node, int s, int e, int pos, ll v){
	if(pos < s || pos > e)
		return;
	if(s == e){
		tr[node] = v;
	}
	else{
		update(2*node, s, (s+e)/2, pos, v);
		update(2*node+1, (s+e)/2+1, e, pos, v);
		
		tr[node] = tr[2*node] + tr[2*node+1];
	}
}
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "rt",stdin);
	cin.tie(0);
    cout.tie(0);
    
    int n, q;
    
    cin>>n>>q;
    
    for(int i = 0; i < n; i++){
    	ll num;
    	
    	cin>>num;
    	update(1, 1, n, i+1, num);
	}
	
	while(q--){
		int x, y, a;
		ll b;
		
		cin>>x>>y>>a>>b;
		
		int e = max(x,y);
		int s = min(x,y);
		
		cout<<seg_sum(1, 1, n, s, e)<<"\n";
		update(1,1,n, a, b);		
	}
	return 0;
}
