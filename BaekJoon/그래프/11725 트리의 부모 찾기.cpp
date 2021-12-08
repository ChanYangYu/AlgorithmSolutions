#include <bits/stdc++.h>
using namespace std;
int parent[100001];
vector<int> edge[100001];
int main(){   
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	int n;
	
	cin>>n;
	
	for(int i = 0; i < n-1; i++){
		int a, b;
		
		cin>>a>>b;
		
		edge[a].push_back(b);
		edge[b].push_back(a);
	} 
	
	queue<int> q;
	
	q.push(1);
	parent[1] = 1;
	
	while(!q.empty()){
		int v = q.front();
		
		q.pop();
		for(int i = 0; i < edge[v].size();i++){
			int node = edge[v][i];
			if(parent[node] == 0){
				parent[node] = v;
				q.push(node);
			}
		}
	}
	
	for(int i = 2; i <= n; i++)
		cout<<parent[i]<<"\n";
    return 0;
}
