#include <bits/stdc++.h>
#define INF 987654321
using namespace std;
int adj[101][101]; 
int main(void){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	int n, m;
	
	cin>>n>>m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			adj[i][j] = INF;
	
	for(int i = 0; i < m; i++){
		int a, b, c;
		
		cin>>a>>b>>c;
		//입력받은 경로 중 가장 작은값 선택 
		adj[a][b] = min(adj[a][b], c);
	}
	
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				//자기자신으로 가는 경로 제외 
				if(i != j && adj[i][j] > adj[i][k] + adj[k][j])
					adj[i][j] = adj[i][k] + adj[k][j];
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(adj[i][j] == INF)
				cout<<"0 ";
			else
				cout<<adj[i][j]<<" ";
		}
		cout<<"\n";
	}
    return 0;
}
