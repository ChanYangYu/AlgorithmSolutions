#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

vector<pii> x;
vector<pii> y;
vector<pii> z;

int parent[100001];

int find(int a){
	if(parent[a] == a){
		return a;
	}
	else{
		return parent[a] = find(parent[a]);
	}
}

void unio(int a, int b){
	if(a < b){
		parent[b] = a;
	}
	else{
		parent[a] = b;
	}
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
   	 
    cin>>n;
    
    for(int i = 1; i <= n; i++){
    	int a, b, c;
    	
    	cin>>a>>b>>c;
    	
    	x.push_back({a, i});
    	y.push_back({b, i});
    	z.push_back({c, i});
    	
    	parent[i] = i;
	}
	
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	sort(z.begin(), z.end());
	
	priority_queue<pair<int, pii> > pq;
	
	for(int i = 0; i < n-1; i++){
		int diff_x = abs(x[i].first - x[i+1].first);
		int diff_y = abs(y[i].first - y[i+1].first);
		int diff_z = abs(z[i].first - z[i+1].first);
		
		pq.push({-diff_x, {x[i].second, x[i+1].second}});
		pq.push({-diff_y, {y[i].second, y[i+1].second}});
		pq.push({-diff_z, {z[i].second, z[i+1].second}});
	}
	
	int res = 0;
	
	while(!pq.empty()){
		int diff = -pq.top().first;
		int a = pq.top().second.first;
		int b = pq.top().second.second;
		
		pq.pop();
		
		int pa = find(a);
		int pb = find(b);
		
		if(parent[a] == parent[b]){
			continue;
		}
		
		res += diff;
		unio(pa, pb);	
	}
	
	cout<<res;
    return 0;
}
