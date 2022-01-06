#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
//#define DEBUG
using namespace std;

int mp[501][501];
int ch[501][501];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	
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
	
	int res = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(ch[i][j] == 0){
				vector<pii> path;
				bool check = false;
				int y = i;
				int x = j;
				
				path.push_back({y, x});
				ch[y][x] = 2;
				
				while(true){
					int d = mp[y][x];
					y = y + dy[d];
					x = x + dx[d];
					
					
					if(y < 1 || y > n || x < 1 || x > m){
						check = true;
						break;
					}
					
					if(ch[y][x] == 2)
						break;
					else if(ch[y][x] == 1){
						check = true;
						break;
					}
					
					ch[y][x] = 2;
					path.push_back({y,x});
				}
				
				if(check){
					for(int k = 0; k < path.size(); k++){
						y = path[k].first;
						x = path[k].second;
						
						ch[y][x] = 1;
					}
					res += path.size();
				}
				
			}
		}
	}
	
	cout<<res;
    return 0;
}
