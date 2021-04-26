#include <bits/stdc++.h>
using namespace std;
int adj[1001][1001];
int check[1001];

int main(){   
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	
	cin>>n>>m;
	
	//양방향 인접행렬 초기화 
	for(int i = 0; i < m; i++){
		int s, e;
		
		cin>>s>>e;
		adj[s][e] = 1;
		adj[e][s] = 1;
	}
	
	int cnt = 0;
	
	
	//모든 component개수 체크 
	for(int i = 1; i <= n; i++){
		//아직 component에 속하지 않은 노드인 경우 
		if(check[i] == 0){
			cnt++;
			check[i] = 1;
			queue<int> q;
			
			q.push(i);
			
			while(!q.empty()){
				int cur = q.front();
				
				q.pop();
				
				for(int j = 1; j <= n; j++){
					if(adj[cur][j] && check[j] == 0){
						check[j] = 1;
						q.push(j);
					}
				}
			}
		}
	}

	cout<<cnt;
    return 0;
}
