#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	ll first = 0;
	ll second = 1;
	int n;
	
	cin>>n;
	
	for(int i = 1; i <= n; i++){
		
		ll tmp = second;
		second = first + second;
		first = tmp;
	}
	
	cout<<first;	
}
