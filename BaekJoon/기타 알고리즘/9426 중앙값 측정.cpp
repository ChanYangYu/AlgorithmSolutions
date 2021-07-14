#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define MAX 65535
using namespace std;

int tr[1<<17];
int nums[250001];
int query(int node, int s, int e, int remain){
	if(s == e){
		return s;
	}
	else{
		if(tr[2*node] < remain)
			return query(2*node+1, (s+e)/2+1, e, remain - tr[2*node]);
		else
			return query(2*node, s, (s+e)/2, remain);
	}
}

void update(int node, int s, int e, int pos, int val){
	if(pos < s || pos > e)
		return;
	if(s == e){
		tr[node] += val;
		return;
	}
	else{
		update(2*node, s, (s+e)/2, pos, val);
		update(2*node+1, (s+e)/2+1, e, pos, val);
		
		tr[node] += val;
	}
}
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","rt",stdin);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    int pos;
    
    cin>>n>>k;
    
    int mid = (k+1)/2;
    
    for(int i = 1; i <= k-1; i++){
    	cin>>nums[i];
    	update(1, 0, MAX, nums[i], 1);
	}
	
	ll res = 0;
	for(int i = k; i <= n; i++){
		cin>>nums[i];
		
		update(1, 0, MAX, nums[i], 1);
		res += query(1, 0, MAX, mid);
		update(1, 0, MAX, nums[i-k+1], -1);
	}
	
	cout<<res;
   	return 0;
}
