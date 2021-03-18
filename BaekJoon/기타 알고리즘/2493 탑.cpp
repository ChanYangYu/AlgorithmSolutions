#include<bits/stdc++.h>
using namespace std;
int h[500001];
int res[500001];

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt","rt",stdin);
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	int n;
	
	cin>>n;
	
	for(int i = 1; i <= n; i++)
		cin>>h[i];
	
	for(int i = n; i >= 1; i--){
		
		if(!pq.empty()){
			while(!pq.empty() && pq.top().first < h[i]){
				int idx = pq.top().second;
				pq.pop();
				res[idx] = i;
			}
		}
		pq.push({h[i], i});
	}
	for(int i = 1; i <= n; i++)
		cout<<res[i]<<" ";
	
	return 0;
}
