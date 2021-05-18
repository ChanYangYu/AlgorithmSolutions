#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	vector<ll> a;
	ll sum = 0;
	int n;
	
	cin>>n;
	
	for(int i = 0; i < n; i++){
		ll x;
		
		cin>>x;
		a.push_back(x);
	}
	
	if(a[0] < 0 && a[n-1] < 0)
		cout<<a[n-2]<<" "<<a[n-1];
	else if(a[0] > 0 && a[n-1] > 0)
		cout<<a[0]<<" "<<a[1];
	else{
		ll diff = 2000000000;
		int begin = 0;
		int end = n-1;
		
		vector<ll> res(2,0);
		
		while(begin < end){
			ll d = abs(a[begin] + a[end]);
			
			if(diff > d){
				diff = d;
				res[0] = a[begin];
				res[1] = a[end];
			}
			if(a[begin] + a[end] < 0)
				begin++;
			
			else if(a[begin] + a[end] > 0)
				end--;
			else
				break;
		}
		cout<<res[0]<<" "<<res[1]; 
	}
	return 0;
}
