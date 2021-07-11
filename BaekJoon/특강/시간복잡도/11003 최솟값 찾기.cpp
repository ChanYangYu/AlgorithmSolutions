#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","rt",stdin);
    cin.tie(0);
    cout.tie(0);
	int n, l;
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	
	cin>>n>>l;
	
	for(int i = 0; i < n; i++){
		int limit = i-l+1;
		int x;
		
		cin>>x;
		pq.push({x, i});
		
		while(pq.top().second < limit)
			pq.pop();
		
		cout<<pq.top().first<<" ";
	}
}
