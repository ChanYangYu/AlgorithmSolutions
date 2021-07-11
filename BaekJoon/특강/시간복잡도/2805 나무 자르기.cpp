#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> trees;
ll n, m;

bool is_possible(ll h){
	ll sum = 0;
	for(int i = 0; i < n; i++){
		if(trees[i] > h)
			sum += trees[i] - h;
		if(sum >= m)
			return true;
	}
	
	return sum >= m;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	cin>>n>>m;
	
	ll mx = 0;
	for(ll i = 0; i < n; i++){
		ll h;
		
		cin>>h;
		trees.push_back(h);
		
		mx = max(mx, h);
	}
	
	ll res = 0;
	
	ll left = 0;
	ll right = mx;
	
	while(left <= right){
		ll mid = (left + right) / 2;
		
		if(is_possible(mid)){
			res = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;	
	}
	
	cout<<res; 
	 
}
