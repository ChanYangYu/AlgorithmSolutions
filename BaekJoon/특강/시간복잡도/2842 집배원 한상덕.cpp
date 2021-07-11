#include <bits/stdc++.h>
#define ll long long

using namespace std;
int n;
char mp[51][51];
int h[51][51];
vector<int> sort_h;
int py, px;
int house_num;

int dy[8] = {-1,1,0,0,1,1,-1,-1};
int dx[8] = {0,0,-1,1,-1,1,1,-1};

int bfs(int left ,int right){
	int ch[51][51] = {0,};
	queue<pair<int, int> > q;
	int cnt = 0;
	
	if(h[py][px] < left || h[py][px] > right)
		return cnt;
	
	ch[py][px] = 1;
	
	q.push({py, px});
	
	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		
		q.pop();
		
		for(int i = 0; i < 8; i++){
			int yy = y + dy[i];
			int xx = x + dx[i];
			
			if(yy < 0 || yy >= n || xx < 0 || xx >= n)
				continue;
			if(ch[yy][xx] == 1)
				continue;
			//피로도 범위를 초과하는 경우 
			if(h[yy][xx] < left || h[yy][xx] > right)
				continue;
			
			//집인 경우 
			if(mp[yy][xx] == 'K')
				cnt++;
			ch[yy][xx] = 1;
			
			q.push({yy,xx});
		}
	}
	
	return cnt;
}

int res = 987654321;
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","rt",stdin);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n;
    
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++){
    		cin>>mp[i][j];
    		if(mp[i][j] == 'P'){
    			py = i;
    			px = j;
			}
			else if(mp[i][j] == 'K')
				house_num++;
			
		}
	}
    		
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++){
    		cin>>h[i][j];
    		sort_h.push_back(h[i][j]);
    	}
    }
    
    sort(sort_h.begin(), sort_h.end());
    int left = 0;
    int right = 0;
    int size = sort_h.size();
    int res = sort_h[size-1] - sort_h[0];
    
    while(left < size && right < size){

    	if(bfs(sort_h[left], sort_h[right]) == house_num){
    		res = min(res, sort_h[right] - sort_h[left]);
    		left++;
		}
		else
			right++;
	}
	
	cout<<res;

