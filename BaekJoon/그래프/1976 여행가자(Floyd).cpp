#include <bits/stdc++.h>
#define MAX 987654321
using namespace std;
int adj[201][201];
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	int n,m;
	
	cin>>n>>m;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin>>adj[i][j];
			//자기자신으로 가는경우 아닌경우 
			if(adj[i][j] == 0 && i != j)
				adj[i][j] = MAX;
		}
	}
	
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				//k를 거쳐서 가는 경우 
				if(adj[i][k] + adj[k][j] < adj[i][j])
					adj[i][j] = adj[i][k] + adj[k][j];
			}
		}
	}
	
	int prev;
	cin>>prev;
	
	for(int i = 1; i < m; i++){
		int cur;
		cin>>cur;
		if(adj[prev][cur] == MAX){
			cout<<"NO";
			return 0;
		}
        prev = cur;
	}
	cout<<"YES";
	return 0;
}
