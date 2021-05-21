#include <bits/stdc++.h>
#define ll long long
using namespace std;
int mp[9][9];
vector<pair<int, int> > blank;

//3 * 3 사각형 탐색 
bool check_rectangle(int y, int x, int t){
	int ry, rx;
	
	if(y < 3)
		ry = 0;
	else if(y < 6)
		ry = 3;
	else
		ry = 6;
	
	if(x < 3)
		rx = 0;
	else if(x < 6)
		rx = 3;
	else
		rx = 6;
	
	for(int i = ry; i < ry+3; i++)
		for(int j = rx; j < rx+3; j++)
			if(mp[i][j] == t)
				return false; 
	
	return true;
}

//빈칸 백트래킹 
bool solve(int idx){
	if(idx == blank.size())
		return true;
	
	int y = blank[idx].first;
	int x = blank[idx].second;
	
	for(int i = 1; i <= 9; i++){
		//3*3 사각형에 이미 있는 숫자인 경우 
		if(!check_rectangle(y, x, i))
			continue;
		
		bool prom = true;
		//row, col에 이미 있는 숫자인 경우 prom = false 
		for(int j = 0; j < 9; j++){
			if(mp[y][j] == i || mp[j][x] == i){
				prom = false;
				break;
			}
		}
		
		//유망한 경우 
		if(prom){
			mp[y][x] = i;
			//탐색시작 
			if(solve(idx+1))
				return true;
			mp[y][x] = 0;
		}
	}
	return false;
}
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	
	for(int i = 0; i < 9; i++){
		string row;
		
		cin>>row;
		
		for(int j = 0; j < 9; j++){
			mp[i][j] = row[j] - '0';
			if(mp[i][j] == 0)
				blank.push_back({i,j});
		}
	}
	
	bool res = solve(0);
	
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++)
			cout<<mp[i][j];
		cout<<"\n";
	}
	
	return 0;
}
