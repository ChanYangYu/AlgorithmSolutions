#include <bits/stdc++.h>

using namespace std;

//https://www.acmicpc.net/problem/2342
int cache[100001][5][5];


int calc_power(int prev, int next){
	if(prev == 0)
		return 2;
	if(prev == next)
		return 1;
	
	if(prev == 1){
		if(next == 2 || next == 4)
			return 3;
		else
			return 4;
	}
	else if(prev == 2){
		if(next == 1 || next == 3)
			return 3;
		else
			return 4;
	}
	else if(prev == 3){
		if(next == 2 || next == 4)
			return 3;
		else
			return 4;
	}
	else{
		if(next == 3 || next == 1)
			return 3;
		else
			return 4;
	}
}

int main(int argc, char** argv)
{
	vector<int> cmd;
	int x;
	
	cin>>x;
	
	while(x != 0){
		cmd.push_back(x);
		cin>>x;
	}
	
	if(cmd.size() == 0){
		cout<<"0";
		return 0;
	}
	memset(cache, -1, sizeof(cache));
	
	cache[0][cmd[0]][0] = 2;
	cache[0][0][cmd[0]] = 2;
	
	for(int i = 1; i < cmd.size(); i++){
		for(int l = 0; l < 5; l++){
			for(int r = 0; r < 5; r++){
				if(cache[i-1][l][r] != -1){
					int next = cmd[i];

					//left 이동 경우
					if(next != r){
						int power = calc_power(l, next);
						
						if(cache[i][next][r] == -1)
							cache[i][next][r] = cache[i-1][l][r] + power;
						else
							cache[i][next][r] = min(cache[i][next][r], cache[i-1][l][r] + power);
					} 
					//right 이동 경우 
					if(next != l){
						int power = calc_power(r, next);
						
						if(cache[i][l][next] == -1)
							cache[i][l][next] = cache[i-1][l][r] + power;
						else
							cache[i][l][next] = min(cache[i][l][next], cache[i-1][l][r] + power);
					}
				}
			}
		}
		
	}
	
	int res = 987654321;
	for(int l = 0; l < 5; l++)
		for(int r = 0; r < 5; r++)
			if(cache[cmd.size()-1][l][r] != -1)
				res = min(res, cache[cmd.size()-1][l][r]);
	
	cout<<res;		
	return 0;
}
