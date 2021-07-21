#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

vector<pii> nexts[20001];
int ch[20001];
int res[20001];

int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","rt",stdin);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	int s;
	
	cin>>n>>m>>s;
  
  	while(m--){
  		int u, v, w;
		
		cin>>u>>v>>w;
		
		nexts[u].push_back({v,w});  	
	}
	
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	
	pq.push({0, s});
	
	while(!pq.empty()){
		int cur_weight = pq.top().first;
		int cur = pq.top().second;
		
		pq.pop();
		
		if(ch[cur] == 1)
			continue;
		ch[cur] = 1;
		res[cur] = cur_weight;
		
		for(int i = 0; i < nexts[cur].size(); i++){
			int next = nexts[cur][i].first;
			int w = nexts[cur][i].second;
			
			pq.push({cur_weight + w, next});
		}
	}
	
	for(int i = 1; i <= n; i++){
		if(ch[i] == 0)
			cout<<"INF\n";
		else
			cout<<res[i]<<"\n";
	}
   	return 0;
}
