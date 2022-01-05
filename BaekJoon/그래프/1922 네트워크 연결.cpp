#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

int p[1001];
int m_find(int a){
	if(a == p[a])
		return a;
	else
		return p[a] = m_find(p[a]);
}

void m_union(int a, int b){
	if(a < b)
		p[b] = a;
	else
		p[a] = b;
}

vector<pair<int, pair<int, int> > > edges;

int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","rt",stdin);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    
	cin>>n>>m;
	
	for(int i = 0; i <= n; i++)
		p[i] = i;
	
	while(m--){
		int a, b, c;
		
		cin>>a>>b>>c;
		
		edges.push_back({c,{a,b}});
	}
	
	sort(edges.begin(), edges.end());
	
	int res = 0;
	for(int i = 0; i < edges.size(); i++){
		int pa = m_find(edges[i].second.first);
		int pb = m_find(edges[i].second.second);
		
		if(pa == pb)
			continue;
		m_union(pa, pb);
		res += edges[i].first;
	}
	
	cout<<res;
	return 0;
}
