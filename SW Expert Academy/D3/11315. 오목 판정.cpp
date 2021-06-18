#include <bits/stdc++.h>
#define ll long long
using namespace std;

char mp[21][21];

bool check_five(int y, int x, int n){
	//세로 
	for(int i = 0; i < 5; i++){
		if(y+i >= n)
			break;
		if(mp[y+i][x] != 'o')
			break;
		if(i == 4)
			return true;
	}
	
	//가로 
	for(int i = 0; i < 5; i++){
		if(x+i >= n)
			break;
		if(mp[y][x+i] != 'o')
			break;
		if(i == 4)
			return true;
	}
	
	//우 대각 
	for(int i = 0; i < 5; i++){
		if(x+i >= n || y+i >= n)
			break;
		if(mp[y+i][x+i] != 'o')
			break;
		if(i == 4)
			return true;
	}
	
	//좌 대각 
	for(int i = 0; i < 5; i++){
		if(x-i < 0 || y+i >= n)
			break;
		if(mp[y+i][x-i] != 'o')
			break;
		if(i == 4)
			return true;
	}
	
	
	return false; 
}
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	int test;
	
	cin>>test;
	
	for(int t = 1; t <= test; t++){
		int n;
		
		cin>>n;
		
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				cin>>mp[i][j];
		
		bool check = false;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(mp[i][j] == 'o'){
					check = check_five(i, j, n);
					if(check)
						break;
				}
			}
			if(check)
				break;
		}
		
		if(check)
			cout<<"#"<<t<<" YES"<<"\n";
		else
			cout<<"#"<<t<<" NO"<<"\n";
	}
	return 0;
}
