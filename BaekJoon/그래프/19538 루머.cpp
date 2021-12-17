#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

vector<int> relation[200001];
int rumor_cnt[200001];
int res[200001];
bool trust_rumor[200001];

int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","rt",stdin);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    
    cin>>n;
    for(int i = 1; i <= n; i++){
    	int t;
    	
    	cin>>t;
    	
    	while(t != 0){
    		relation[i].push_back(t);
    		cin>>t;
		}
	}
	
	cin>>m;
	
	for(int i = 0; i < m; i++){
		int r;
		
		cin>>r;
		trust_rumor[r] = true;
		pq.push({0, r});
	}
	
	memset(res, -1, sizeof(res));
	
	while(!pq.empty()){
		int day = pq.top().first;
		int person = pq.top().second;
		
		pq.pop();
		res[person] = day;
		
		for(int i = 0; i < relation[person].size(); i++){
			int other = relation[person][i];
			int threshold = relation[other].size() / 2 + relation[other].size() % 2;
			
			if(trust_rumor[other])
				continue;
			rumor_cnt[other]++;
			
			if(rumor_cnt[other] >= threshold){
				trust_rumor[other] = true;
				pq.push({day+1, other});
			}
		}
	}
    
    for(int i = 1; i <= n; i++){
    	cout<<res[i]<<" ";
	}
   	return 0;
}
