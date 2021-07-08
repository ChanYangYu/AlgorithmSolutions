#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","rt",stdin);
    cin.tie(0);
    cout.tie(0);
    
    ll x, y;
    
    cin>>x>>y;
    
    if(x - y == 0){
    	cout<<"-1";
    	return 0;
	}
	
	ll left = 0;
	ll right = 1000000000;
	
	ll cur = (y*100) / x;
	
	while(left <= right){
		ll mid = (left + right) / 2;
		
		ll per = ((y+mid)*100) / (x+mid);
		
		if(cur < per)
			right = mid-1;
		else
			left = mid+1;
	}
	
	ll per = ((y+left)*100) / (x+left);
	if(per == cur)
		cout<<"-1";
	else
		cout<<left;

}
