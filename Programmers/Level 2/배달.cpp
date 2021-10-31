#include <bits/stdc++.h>
using namespace std;

int adj[51][51];
int dis[51];
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    for(int i = 0; i < road.size(); i++){
        int a = road[i][0];
        int b = road[i][1];
        int c = road[i][2];
        
        if(adj[a][b] == 0){
            adj[a][b] = c;
            adj[b][a] = c;
        }
        else{
            adj[a][b] = min(c, adj[a][b]);
            adj[b][a] = min(c, adj[b][a]);
        }
    }
    
    priority_queue<pair<int, int> > pq;
    
    
    for(int i = 1; i <= N; i++){
        dis[i] = 987654321;
        if(adj[1][i] != 0){
            pq.push({-adj[1][i], i});
        }
    }
    
    dis[1] = 0;
    while(!pq.empty()){
        int d = -pq.top().first;
        int p = pq.top().second;
        
        pq.pop();
        
        if(dis[p] < d)
            continue;
        dis[p] = d;
        
        for(int i = 1; i <= N; i++){
            if(adj[p][i] != 0 && dis[i] > dis[p]+adj[p][i]){
                pq.push({-(dis[p]+adj[p][i]), i});
            }
        }
    }
    
    for(int i = 1; i <= N; i++){
        if(dis[i] <= K)
            answer++;
    }
    return answer;
}
