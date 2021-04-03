#include <bits/stdc++.h>
using namespace std;
int cache[10000001];
int price[21];
int prefer[21];
int n;

int main() {
	cin.tie(0);
	freopen("input.txt", "rt", stdin);
	int t;
	int won;
	
	cin>>t;
	
	for(int k = 0; k < t; k++){
		cin>>n>>won;
		
		won /= 100;
		
		memset(cache, 0, sizeof(cache));
		
		for(int i = 0; i < n; i++){
			cin>>price[i]>>prefer[i];
			price[i] /= 100;
		}
		
		int res = 0;
		for(int i = 0; i < n; i++){
			for(int j = price[i]; j <= won; j++){
				cache[j] = max(cache[j], cache[j - price[i]] + prefer[i]);
				res = max(res, cache[j]);
			}
		}
		
		cout<<res<<"\n";
	}
	return 0;
}
