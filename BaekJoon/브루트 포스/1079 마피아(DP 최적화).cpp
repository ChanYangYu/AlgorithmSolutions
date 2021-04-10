#include<bits/stdc++.h>
using namespace std;
//DP 3^16 상태저장 
char state[43046721];
int check[16];
int r[16][16];
int crime[16];
int n;
int square[16];
int mafia;

char solve(int idx, int remain){
	if(remain == 1)
		return 0;
	
	char& ret = state[idx];
	
	if(ret != -1)
		return ret;
	
	//밤 
	if(remain % 2 == 0){
		ret = 1;
		//살아있는 사람 중에 죽일사람 선택 
		for(int i = 0; i < n; i++){
			if(i != mafia && check[i] == 0){
				check[i] = 1;
				//마피아에 의해죽은 경우 square[i] * 1 
				for(int k = 0; k < n; k++)
					crime[k] += r[i][k];
				
				char res = solve(idx + square[i], remain-1) + 1;
				ret = max(ret, res);
				for(int k = 0; k < n; k++)
					crime[k] -= r[i][k];
				check[i] = 0;
			}
		}
	}
	//낮 
	else{
		int target = -1;
		int mx = 0;
		//전체 살아있는 사람 중 죽일사람 체크 
		for(int i = 0; i < n; i++){
			//생사 체크
			if(check[i] == 1)
				continue;
			//유죄율 체크 
			if(mx < crime[i]){
				target = i;
				mx = crime[i];
			}
		}
		//마피아가 죽은 경우
		if(target == mafia)
			return ret = 0;
		check[target] = 1;
		//유죄율로 죽은경우 square[i]*2 
		ret = solve(idx + square[target]*2, remain-1);
		check[target] = 0;
	}
	
	return ret;
}
int main(int argc, char** argv)
{
    cin.tie(0);
    //freopen("input.txt","rt",stdin);
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>crime[i];
    
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++)
    		cin>>r[i][j];
	}
	
	cin>>mafia;
	
	square[0] = 1;
	for(int i = 1; i < 16; i++)
    	square[i] = square[i-1] * 3;
    
    memset(state, -1, sizeof(state));
    
    int res = solve(0, n);
    
    cout<<res;
    
    return 0;
}
