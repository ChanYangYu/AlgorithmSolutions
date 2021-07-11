#include <bits/stdc++.h>
#define ll long long
#define range c_plus_d.begin(),c_plus_d.end()
using namespace std;

int a[4000];
int b[4000];
int c[4000];
int d[4000];

int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","rt",stdin);
    cin.tie(0);
    cout.tie(0);
    int n;
    
    cin>>n;
    for(int i = 0; i < n; i++){
    	cin>>a[i];
    	cin>>b[i];
    	cin>>c[i];
    	cin>>d[i];
	}
	
	vector<int> c_plus_d;
	
	ll res = 0;
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			c_plus_d.push_back(c[i] + d[j]);
	
	sort(range);
	
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int target = -(a[i] + b[j]);
			
			res += upper_bound(range, target) - lower_bound(range, target);
		}
	}
	cout<<res;
}
