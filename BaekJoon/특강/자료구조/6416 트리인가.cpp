#include <bits/stdc++.h>
#define ll long long
using namespace std;

void check(vector<pair<int, int> > e, int cnt){
	unordered_map<int, int> parent;
	set<int> p;
	bool is_tree = true;
	
	if(e.size() == 0){
		cout<<"Case "<<cnt<<" is a tree.\n";
		return;
	}
	for(int i = 0; i < e.size(); i++){
		int u = e[i].first;
		int v = e[i].second;
		
		p.insert(u);
		
		//이미 부모노드가 있는 경우 
		if(parent[v] != 0){
			is_tree = false;
			break;
		}
		
		parent[v] = u;
	}
	
	int root_cnt = 0;
	set<int>::iterator it;
	for(it = p.begin(); it != p.end(); it++){
		int candidate = *it;
		if(parent[candidate] == 0){
			root_cnt++;
		}
	}
	
	if(is_tree && root_cnt == 1)
		cout<<"Case "<<cnt<<" is a tree.\n";
	else
		cout<<"Case "<<cnt<<" is not a tree.\n";	
	
	
} 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    vector<pair<int, int> > edges;
    int cnt = 0;
    
    while(true){
    	int u, v;
    	
    	cin>>u>>v;
    	
    	if(u == 0 && v == 0){
    		cnt++;
    		
    		check(edges, cnt);
    		edges.clear();
		}
		else if(u == -1 && v == -1)
			break;
		else
			edges.push_back({u,v});
	}
    
}
