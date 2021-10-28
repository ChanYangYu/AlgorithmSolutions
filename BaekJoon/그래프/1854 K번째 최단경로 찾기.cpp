#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define MAX 987654321
using namespace std;
vector<pii> nexts[1001];
int di[1001];
int visit_cnt[1001];

int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","rt",stdin);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, k;
    
    cin>>n>>m>>k;
    
    while(m--){
		int a, b, c;
		
		cin>>a>>b>>c;
		
		nexts[a].push_back({b,c});    	
	}
	
	for(int i = 1; i <= n; i++)
		di[i] = MAX;
	
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	
	
	pq.push({0,1});
	
	while(!pq.empty()){
		int cur_d = pq.top().first;
		int cur = pq.top().second;
		
		pq.pop();
		
		if(di[cur] != MAX)
			continue;
		
		visit_cnt[cur]++;
		if(visit_cnt[cur] == k)
			di[cur] = cur_d;
		
		for(int i = 0; i < nexts[cur].size(); i++){
			int next = nexts[cur][i].first;
			int next_d = nexts[cur][i].second;
			
			pq.push({cur_d + next_d, next});
		}
	}
	
	for(int i = 1; i <= n; i++){
		if(di[i] == MAX)
			cout<<"-1\n";
		else
			cout<<di[i]<<"\n";
	}
   	return 0;
}
