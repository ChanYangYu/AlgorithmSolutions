#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
//#define DEBUG
using namespace std;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int mp[1001][1001];
int ch[1001][1001];
int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    int res = 0;
    
    cin>>n>>m;
    
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++){
    		char x;
    		
    		cin>>x;
    		
    		if(x == 'D')
    			mp[i][j] = 0;
    		else if(x == 'U')
    			mp[i][j] = 1;
    		else if(x == 'L')
    			mp[i][j] = 2;
    		else
    			mp[i][j] = 3;
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(ch[i][j] == 0){
				queue<pii> q;
				vector<pii> v;
				int group = res+1;
				
				q.push({i,j});
				v.push_back({i,j});
				ch[i][j] = group;
				
				while(!q.empty()){
					int y = q.front().first;
					int x = q.front().second;
					
					q.pop();
					
					int yy = y + dy[mp[y][x]];
					int xx = x + dx[mp[y][x]];
					
					if(ch[yy][xx] != 0){					
						if(ch[yy][xx] == group)
							res++;
						// 이전 그룹과 연결되는 경우 
						else
							for(int k = 0; k < v.size(); k++)
								ch[v[k].first][v[k].second] = res;
						break;
					}

					ch[yy][xx] = group;
					q.push({yy,xx});
					v.push_back({yy, xx});
				}
				
				#ifdef DEBUG
				for(int k = 1; k <= n; k++){
					for(int l = 1; l <= m; l++)
						cout<<ch[k][l]<<" ";
					cout<<"\n";
				}
				cout<<"============================\n";
				#endif
			}
		}
	}
	
	cout<<res;
    return 0;
}
