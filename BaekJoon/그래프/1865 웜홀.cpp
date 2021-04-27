//벨만 포드 알고리즘 
#include <bits/stdc++.h>
#define MAX 987654321
using namespace std;
class Edge{
	public:
		int s;
		int e;
		int t;
		Edge(int s, int e, int t){
			this->s = s;
			this->e = e;
			this->t = t;
		}
};
vector<Edge> edges;
int dst[501];
int main(){   
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	int t;
	
	cin>>t;
	
	for(int k = 0; k < t; k++){
		int n, m, w;
		
		cin>>n>>m>>w;
		edges.clear();
		for(int i = 0; i < m; i++){
			int s, e, t;
			
			cin>>s>>e>>t;
			edges.push_back(Edge(s,e,t));
			edges.push_back(Edge(e,s,t));
		}
		
		for(int i = 0; i < w; i++){
			int s,e,t;
			
			cin>>s>>e>>t;
			edges.push_back(Edge(s,e,-t));
		}
		
		for(int i = 1; i <= n; i++)
			dst[i] = MAX;
		
		//음수 사이클 존재 여부를 체크하므로 시작점 필요x 
		bool has_cycle = false;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < edges.size(); j++){
				int s = edges[j].s;
				int e = edges[j].e;
				int t = edges[j].t;
				
				//음수 edge인 경우 업데이트 
				if(dst[e] > dst[s] + t){
					dst[e] = dst[s] + t;
					
					//n번 동안 업데이트 발생시 음수사이클 존재
					if(i == n-1)
						has_cycle = true;
				}	
			}
		}	
		if(has_cycle)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
    return 0;
}

//플로이드-와샬 알고리즘
/* 
#include <bits/stdc++.h>
#define MAX 987654321
using namespace std;
int adj[501][501];
int main(){   
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	int t;
	
	cin>>t;
	
	for(int k = 0; k < t; k++){
		int n, m, w;
		
		cin>>n>>m>>w;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				adj[i][j] = MAX;
		for(int i = 0; i < m; i++){
			int s, e, t;
			
			cin>>s>>e>>t;
			
			adj[s][e] = min(adj[s][e], t);
			adj[e][s] = min(adj[e][s], t);
		}
		
		for(int i = 0; i < w; i++){
			int s,e,t;
			
			cin>>s>>e>>t;
			
			adj[s][e] = min(adj[s][e], -t);
		}
		
		for(int k = 1; k <= n; k++){
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					if(adj[i][j] > adj[i][k] + adj[k][j])
						adj[i][j] = adj[i][k] + adj[k][j];
				}
			}
		}
		
		bool check = false;
		for(int i = 1; i <= n; i++){
			if(adj[i][i] < 0){
				check = true;
				break;
			}
		}
		
		if(check)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
    return 0;
}
*/
