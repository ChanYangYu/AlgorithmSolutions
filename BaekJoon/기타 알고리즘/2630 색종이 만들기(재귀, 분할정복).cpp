#include <bits/stdc++.h>
using namespace std;
int white, blue;
int n;
int mp[129][129];

void solve(int y, int x, int size)
{
	bool check = true;
	
	int start = mp[y][x];
	//현재 색종이가 한색으로 칠해져있는지 체크 
	for(int i = y; i < y+size; i++){
		for(int j = x; j < x+size; j++){
			if(start != mp[i][j]){
				check = false;
				break;
			}
		}
		if(check == false)
			break;
	}
	
	//모두 한색으로 칠해진 경우 
	if(check){
		if(start == 1)
			blue++;
		else
			white++;
		return;
	}
	else{
		//현재 색종이를 4분할로 나눠서 탐색 
		int n_size = size / 2;
		solve(y, x, n_size);
		solve(y, x + n_size, n_size);
		solve(y + n_size, x, n_size);
		solve(y + n_size, x + n_size, n_size);
	}
}

int main(){   
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin>>mp[i][j];
	
	solve(0,0,n);
	
	cout<<white<<"\n"<<blue;
    return 0;
}
