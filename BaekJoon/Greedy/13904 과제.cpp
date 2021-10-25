#include<bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	priority_queue<pii> pq;
	
	cin>>n;
	
	int mx = 0;
	for(int i = 0; i < n; i++){
		int d, w;
		
		cin>>d>>w;
		
		pq.push({d,w});
		mx = max(mx, d);
	}
	
	int res = 0;
	for(int day = mx; day >= 1; day--){
		priority_queue<pii> tmp;
		
		while(!pq.empty() && pq.top().first >= day){
			
			int d = pq.top().first;
			int w = pq.top().second;
			
			pq.pop();
			tmp.push({w, d});
		}
		if(!tmp.empty()){
			res += tmp.top().first;
			tmp.pop();
		}
		
		while(!tmp.empty()){
			int d = tmp.top().second;
			int w = tmp.top().first;
			
			tmp.pop();
			pq.push({d,w});
		}
	}
	
	cout<<res;
    return 0;
}
