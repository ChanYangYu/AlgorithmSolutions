#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

char mp[26][26];
char backup[26][26];
// ºÏ µ¿ ³² ¼­ 
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int h, w;
int total;

bool possible_A(int d, int y, int x){
    int y1 = y + dy[d];
    int x1 = x + dx[d];
    
    if(y1 < 1 || y1 > h || x1 < 1 || x1 > w)
        return false;
    
    int y2 = y + 2 * dy[d];
    int x2 = x + 2 * dx[d];

    if(y2 < 1 || y2 > h || x2 < 1 || x2 > w)
        return false;
    
    if(mp[y1][x1] != '#' || mp[y2][x2] != '#')
        return false;
        
    return true;
}

int turn_right(int d){
    d = (d+1) % 4;
    
    return d;
}

int turn_left(int d){
    d = (d-1) == -1 ? 3 : d-1;
    
    return d;
}


string execute(int y, int x, int d){
	char mp1[26][26];
	int cnt = 0;
	string cmd = "";
	
	for(int i = 1; i <= h; i++)
		for(int j = 1; j <= w; j++)
			mp1[i][j] = mp[i][j];

    mp1[y][x] = '.';
	cnt++;
	
    while(true){
        if(possible_A(d, y, x)){
            cmd += 'A';
            
            mp1[y+dy[d]][x+dx[d]] = '.';
            mp1[y+2*dy[d]][x+2*dx[d]] = '.';
            y += 2 * dy[d];
            x += 2 * dx[d];
            
            cnt += 2;
        }
        else if(possible_A(turn_left(d), y, x)){
            d = turn_left(d);
            cmd += 'L';
        }
        else if(possible_A(turn_right(d), y, x)){
            d = turn_right(d);
            cmd += 'R';
        }
        else
            break;
    }
    
    if(cnt == total)
    	return cmd;
    else
    	return "IMPOSSIBLE";
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<pii> points;
    cin>>h>>w;

    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            cin>>mp[i][j];

            if(mp[i][j] == '#'){
                points.push_back({i,j});
                total++;
            }
        }
    }
	int sy = 0;
	int sx = 0;
	int sd = -1;
	string cmd = "";
    for(int i = 0; i < points.size(); i++){
        int y = points[i].first;
        int x = points[i].second;
        string res;
        
        for(int j = 0; j < 4; j++){
        	
        	res = execute(y,x,j);
        	if(res == "IMPOSSIBLE")
        		continue;
        	if(sy == 0 && sx == 0){
        		sy = y;
        		sx = x;
        		sd = j;
        		cmd = res;
			}
			else if(cmd.size() > res.size()){
				sy = y;
				sx = x;
				sd = j;
				cmd = res;
			}
		}
    }
    
    cout<<sy<<" "<<sx<<"\n";
    if(sd == 0)
        cout<<"^\n";
    else if(sd == 1)
        cout<<">\n";
    else if(sd == 2)
        cout<<"v\n";
    else
        cout<<"<\n";
    cout<<cmd;
    return 0;
}
