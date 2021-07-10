#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
int main(){
    //ios_base::sync_with_stdio(false);
    //freopen("input.txt", "rt",stdin);
	cin.tie(0);
    cout.tie(0);
	int n;
	
	cin>>n;
	
	if(n == 1)
		return 0;
	
	for(int i = 2; i <= 3200; i++){
		while(n % i == 0){
			cout<<i<<"\n";
			n /= i;
		}
	}
	if(n > 1)
		cout<<n;
}
