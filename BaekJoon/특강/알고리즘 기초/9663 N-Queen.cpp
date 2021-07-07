#include <bits/stdc++.h>
using namespace std;
int res;
int n;
int mp[15][15];
int ch[15];

int prom(int y, int x){
	int j = 1;
	for(int i = 1; i <= y ; i++){
		if(x-i >= 0){
			if(mp[y-i][x-i] == 1)
				return 0;
		}
		if(x+i < n){
			if(mp[y-i][x+i] == 1)
				return 0;
		}
	}
	return 1;
}
void n_queen(int idx){
	if(n == idx){
		res++;
		return;	
	}
	else{
		for(int i = 0; i < n; i++){
			//세로 검사
			if(ch[i] == 0 && prom(idx, i)){
				ch[i] = 1;
				mp[idx][i] = 1;
				n_queen(idx+1);
				mp[idx][i] = 0;
				ch[i] = 0;
			}
		}
	}
}
int main(void){
	ios_base::sync_with_stdio(false);
	
	cin>>n;
	
	n_queen(0);
	cout<<res;
    return 0;
}
