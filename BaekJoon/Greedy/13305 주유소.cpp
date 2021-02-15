#include <bits/stdc++.h>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	long long best;
	long long n;
	long long dis[100000], price[100000];
	
	cin>>n;
	
	for(int i = 0; i < n-1; i++)
		cin>>dis[i];
	for(int i = 0; i < n; i++)
		cin>>price[i];
	
	best = price[0];
	long long res = price[0]*dis[0];
	for(int i = 1; i < n-1; i++){
		if(best > price[i])
			best = price[i];
		res += dis[i]*best;
	}
	cout<<res;
    return 0;
}
