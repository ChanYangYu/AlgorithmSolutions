#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
int A_order[1000001];
ll tr[1<<20];

ll query(int node, int s, int e, int l, int r){
	if(r < s || e < l)
		return 0;
	else if(l <= s && e <= r)
		return tr[node];
	else
		return query(2*node, s, (s+e)/2, l, r) + query(2*node+1, (s+e)/2+1, e, l, r);
}

void update(int node, int s, int e, int pos){
	if(pos < s || pos > e)
		return;
	else if(s == e){
		tr[node]++;
	}
	else{
		update(2*node, s, (s+e)/2, pos);
		update(2*node+1, (s+e)/2+1, e, pos);
		
		tr[node]++;
	}
}
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","rt",stdin);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++){
		int num;
		
		cin>>num;
		A_order[num] = i;
	}	
	
	ll res = 0;
	for(int i = 1; i <= n; i++){
		int num;
		
		cin>>num;
		
		int order = A_order[num];
		res += query(1, 1, n, order+1, n);
		update(1,1,n,order);
	}
	
	cout<<res;
    return 0;
}
