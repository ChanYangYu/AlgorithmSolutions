#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
//#define DEBUG
using namespace std;

int a[100001];
int main(int argc, char** argv)
{
    //ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	ll n, k;
	cin>>n>>k;
	
	ll l = 1;
	ll r = n*n;
	
	while(l <= r){
		ll mid = (l + r) / 2;
		
		ll cnt = 0;
		for(int i = 1; i <= n; i++)
			cnt += min(mid/i, n);
		
		if(cnt >= k)
			r = mid-1;
		else
			l = mid+1;
	}
	
	cout<<l;
	
    return 0;
}
