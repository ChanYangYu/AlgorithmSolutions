#include <bits/stdc++.h>
using namespace std;

int ch[51][51];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

class Data{
	public:
		int y;
		int x;
		int d;
		Data(int y, int x, int d){
			this->y = y;
			this->x = x;
			this->d = d;
		}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "rt", stdin);
    queue<Data> waters;
    queue<Data> g;
    int endy, endx;
    int r, c;
    
    cin>>r>>c;
    
    for(int i = 0; i < r; i++){
    	for(int j = 0; j < c; j++){
    		char c;
    		cin>>c;
    		
    		if(c == 'S'){
    			ch[i][j] = 1;
    			g.push(Data(i, j, 0));
    		}
    		else if(c == '*'){
    			ch[i][j] = 1;
    			waters.push(Data(i,j,0));
    		}
    		else if(c == 'D'){
    			endy = i;
    			endx = j;
			}
			else if(c == 'X')
				ch[i][j] = 1;
		}
	}
	
	while(!g.empty()){
		int y = g.front().y;
		int x = g.front().x;
		int d = g.front().d;
		
		g.pop();
		
		if(y == endy && x == endx){
			cout<<d;
			return 0;
		}
		
		if(d == waters.front().d){
			while(!waters.empty()){
				int wy = waters.front().y;
				int wx = waters.front().x;
				int wd = waters.front().d;
				
				if(d < wd)
					break;
				waters.pop();
				
				for(int i = 0; i < 4; i++){
					int yy = wy + dy[i];
					int xx = wx + dx[i];
					
					if(yy < 0 || yy >= r || xx < 0 || xx >= c)
						continue;
					if(ch[yy][xx] == 1 || (yy == endy && xx == endx))
						continue;
					ch[yy][xx] = 1;
					waters.push(Data(yy, xx, wd+1));
				}
			}
//			for(int i = 0; i < r; i++){
//				for(int j = 0; j < c; j++)
//					cout<<ch[i][j];
//				cout<<"\n";
//			}
//			cout<<"======================\n";
		}
		for(int i = 0; i < 4; i++){
			int yy = y + dy[i];
			int xx = x + dx[i];
			
			if(yy < 0 || yy >= r || xx < 0 || xx >= c)
				continue;
			
			if(ch[yy][xx] == 1)
				continue;
			ch[yy][xx] = 1;
			g.push(Data(yy, xx, d+1));
		}
	}
	cout<<"KAKTUS";
	return 0;
}
