#include<bits/stdc++.h>

using namespace std;

class Data{
	public:
		int t;
		int d;
		int y;
		int x;
		
		Data(int t, int d, int y, int x){
			this->t = t;
			this->d = d;
			this->y = y;
			this->x = x;
		};
};

// 동 : 0, 서 : 1, 남 : 2, 북 : 3
// 좌 : 0, 직 : 1, 우 : 2
vector<int> info[4][3] = {
    {{-1,0},{0,1},{1,0}},
    {{1,0},{0,-1},{-1,0}},
    {{0,1},{1,0},{0,-1}},
    {{0,-1},{-1,0},{0,1}}
};
pair<int, vector<int> >  sig[12] = {
    {0,{0,1,2}},
    {3,{0,1,2}},
    {1,{0,1,2}},
    {2,{0,1,2}},
    {0,{0,1}},
    {3,{0,1}},
    {1,{0,1}},
    {2,{0,1}},
    {0,{1,2}},
    {3,{1,2}},
    {1,{1,2}},
    {2,{1,2}}
};

int mp[101][101][4];
int ch[101][101];

int change_direction(int d, int lsr){
	if(lsr == 1)
		return d;
	else if(lsr == 0){
		if(d == 0)
			return 3;
		else if(d == 1)
			return 2;
		else if(d == 2)
			return 0;
		else
			return 1;
	}
	else{
		if(d == 0)
			return 2;
		else if(d == 1)
			return 3;
		else if(d == 2)
			return 1;
		else
			return 0;
	}
		
}
int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    int n, t;

    cin>>n>>t;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 0; k < 4; k++){
                int s;

                cin>>s;

                //signal 0 ~ 11
                mp[i][j][k] = s-1;
            }
        }
    }

    int res = 1;
    queue<Data> q;
    q.push(Data(0,3,1,1));
    ch[1][1] = 1;
    
    while(!q.empty()){
    	int cur_t = q.front().t;
    	int d = q.front().d;
    	int y = q.front().y;
    	int x = q.front().x;
    	
    	q.pop();
    	
    	if(cur_t == t)
    		continue;
    		
    	int turn = mp[y][x][cur_t % 4];
    	pair<int, vector<int> > s = sig[turn];
    	
    	//진행방향이 다른 경우 
    	if(s.first != d)
    		continue;
    	
    	for(int i = 0; i < s.second.size(); i++){
    		int lsr = s.second[i];
    		int yy = y + info[d][lsr][0];
    		int xx = x+ info[d][lsr][1];
    		
    		if(yy < 1 || yy > n || xx < 1 || xx > n)
    			continue;
    		if(ch[yy][xx] == 0)
    			res++;
    		ch[yy][xx] = 1;
    		
    		//방향전환 
    		q.push(Data(cur_t+1, change_direction(d, lsr), yy, xx));
		} 
	}

    cout<<res;

}
