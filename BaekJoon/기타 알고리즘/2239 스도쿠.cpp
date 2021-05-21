#include <bits/stdc++.h>
#define ll long long
using namespace std;
int mp[9][9];
vector<pair<int, int> > blank;

//3 * 3 �簢�� Ž�� 
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

//��ĭ ��Ʈ��ŷ 
bool solve(int idx){
	if(idx == blank.size())
		return true;
	
	int y = blank[idx].first;
	int x = blank[idx].second;
	
	for(int i = 1; i <= 9; i++){
		//3*3 �簢���� �̹� �ִ� ������ ��� 
		if(!check_rectangle(y, x, i))
			continue;
		
		bool prom = true;
		//row, col�� �̹� �ִ� ������ ��� prom = false 
		for(int j = 0; j < 9; j++){
			if(mp[y][j] == i || mp[j][x] == i){
				prom = false;
				break;
			}
		}
		
		//������ ��� 
		if(prom){
			mp[y][x] = i;
			//Ž������ 
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
