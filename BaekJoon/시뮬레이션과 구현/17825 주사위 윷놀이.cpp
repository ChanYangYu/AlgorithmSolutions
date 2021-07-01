#include <bits/stdc++.h>

using namespace std;
int mp[33] = {
	0, 2, 4, 6, 8 ,10, 12, 14, 16, 18, 20,
	22, 24, 26, 28, 30, 32, 34, 36, 38, 40,
	22, 24, 25, 30, 35,
	13, 16, 19,
	28, 27, 26, 0
	}; 
int ch[33];
int pos[4];
int num[10];
int res;

int move(int cp, bool isBlue){
	if(cp == 5 && isBlue)
		return 26;
	else if(cp == 10 && isBlue)
		return 21;
	else if(cp == 15 && isBlue)
		return 29;
	else if(cp == 26)
		return 27;
	else if(cp == 27)
		return 28;
	else if(cp == 28)
		return 23;
	else if(cp == 29)
		return 30;
	else if(cp == 30)
		return 31;
	else if(cp == 31)
		return 23;
	else if(cp == 25)
		return 20;
	else if(cp == 20)
		return 32;
	else if(cp == 32)
		return 32;
	else
		return cp+1;
}

void solve(int idx, int score){
	if(idx == 10){
		res = max(res, score);
		return;
	}
	
	for(int i = 0; i < 4; i++){
		int cp = pos[i];
		int d = num[idx];
		
		if(cp == 5 || cp == 10 || cp == 15){
			cp = move(cp, true);
			d--;
		}
		
		while(d--)
			cp = move(cp, false);
		
		if(cp != 32 && ch[cp] == 1)
			continue;
		
		int tmp = pos[i];
		pos[i] = cp;
		ch[tmp] = 0;
		ch[cp] = 1;
		
		solve(idx+1, score + mp[cp]);
		
		pos[i] = tmp;
		ch[tmp] = 1;
		ch[cp] = 0;
	}
}
 
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "rt", stdin);
    
    for(int i = 0; i < 10; i++)
    	cin>>num[i];
    
    solve(0, 0);
    cout<<res;
    return 0;
}
