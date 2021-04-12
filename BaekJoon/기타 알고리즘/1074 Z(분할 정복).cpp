#include<bits/stdc++.h>
using namespace std;
int n, r, c;
int res;
int cnt;

void solve(int s, int i, int j){
	//4개 공간으로 나눠서 탐색 
	if(s > 2){
		int new_size = s/2;
		//범위에 속하면 탐색 
		if((i <= r && r < i + new_size) && (j <= c && c < j + new_size)){
			solve(new_size, i, j);
			return;
		}
		//해당부분 점프 
		cnt += (new_size * new_size);
		
		//범위에 속하면 탐색 
		if((i <= r && r < i + new_size) && (j + new_size <= c && c < j + (2 * new_size))){
			solve(new_size, i, j + new_size);
			return;
		}
		
		//해당부분 점프 
		cnt += (new_size * new_size);
	
		//범위에 속하면 탐색 
		if((i + new_size <= r && r < i + (2 * new_size)) && (j <= c && c < j + new_size)){
			solve(new_size, i + new_size, j);
			return;
		}
		//해당부분 점프 
		cnt += (new_size * new_size);
		
		//범위에 속하면 탐색 
		if((i + new_size <= r && r < i + (2 * new_size)) && (j + new_size <= c && c < j + (2 * new_size))){
			solve(new_size, i + new_size, j + new_size);
			return;
		}
		//해당부분 점프 
		cnt += (new_size * new_size);
	}
	//현재 탐색 공간이 2 * 2칸인 경우 
	else{
		//4칸 중 일치하는 칸 탐색 
		for(int y = i; y < i + 2; y++){
			for(int x = j; x < j + 2; x++){
				if(y == r && x == c){
					res = cnt;
					return;
				}
				cnt++;
			}
		}
	}
}

int main(int argc, char** argv)
{
    cin.tie(0);
    //freopen("input.txt","rt",stdin);
    
    cin>>n>>r>>c;
    
    int s = 1;
    for(int i = 0; i < n; i++)
    	s *= 2;
    
    solve(s, 0, 0);
    
    cout<<res;

    return 0;
}
