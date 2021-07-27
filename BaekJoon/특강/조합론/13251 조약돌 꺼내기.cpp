#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

int m;
int colors[51];
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "rt",stdin);
	cin.tie(0);
    cout.tie(0);
	
	cout<<fixed;
	cout.precision(10);
	cin>>m;
	
	int sum = 0;
	for(int i = 0; i < m; i++){
		cin>>colors[i];
		sum+= colors[i];
	}
	
	int k;
	
	cin>>k;
	
	double res = 0.0;
	
	for(int i = 0; i < m; i++){
		if(colors[i] >= k){
			double tmp = 1.0;
			for(int j = 0; j < k; j++){
				tmp *= (double)(colors[i]-j) / (double)(sum-j);
			}
			res += tmp;
		}
	}
	
	cout<<res;
	return 0;
}
