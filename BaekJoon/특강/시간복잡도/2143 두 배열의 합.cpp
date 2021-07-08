#include <bits/stdc++.h>
#define ll long long
#define range b_sub.begin(),b_sub.end()
using namespace std;

int a[1000];
int b[1000];

int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","rt",stdin);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    int t;
    vector<int> b_sub;
    
    cin>>t;
    cin>>n;
    
    for(int i = 0; i < n; i++)
    	cin>>a[i];
    
    cin>>m;
    for(int i = 0; i < m; i++)
    	cin>>b[i];
    
    for(int s = 0; s < m; s++){
    	int sum = 0;
    	for(int e = s; e < m; e++){
    		sum += b[e];
    		b_sub.push_back(sum);
		}
	}
	
	sort(range);	
	
	ll res = 0;
	for(int s = 0; s < n; s++){
    	int sum = 0;
    	for(int e = s; e < n; e++){
    		sum += a[e];
    		int target = t - sum;
    		int cnt = upper_bound(range, target) - lower_bound(range, target);
    		
    		res += cnt;
		}
	}
	
	cout<<res;
}
