#include<bits/stdc++.h>
using namespace std;
int mp[101][101];

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt","rt",stdin);
	int n, l;
	int res = 0;
	
	cin>>n>>l;
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin>>mp[i][j];
	
	for(int i = 0; i < n; i++){
		int con = 1;
		int cur = mp[i][0];
		res += 1;
		for(int j = 1; j < n; j++){
			//두 블럭차가 2이상일때 
			if(abs(cur - mp[i][j]) > 1){
				res -= 1;
				break;
			}
			//더 높은 블럭을 만난 경우 
			else if(mp[i][j] > cur){
				//현재 블럭이 l개 이하 연속인경우 
				if(con < l){
					res -= 1;
					break;
				}
				con = 1;
				cur = mp[i][j];
			}
			else if(mp[i][j] < cur){
				int start = mp[i][j];
				int prom = 1;
				for(int k = 0; k < l; k++){
					if(mp[i][j+k] != start){
						prom = 0;
						break;
					}
				}
				if(!prom){
					res -= 1;
					break;
				}
				j += l-1;
				con = 0;
				cur = mp[i][j];
			}
			else
				con += 1;
		}
	}
	
	
	for(int j = 0; j < n; j++){
		int con = 1;
		int cur = mp[0][j];
		res += 1;
		for(int i = 1; i < n; i++){
			//두 블럭차가 2이상일때 
			if(abs(cur - mp[i][j]) > 1){
				res -= 1;
				break;
			}
			//더 높은 블럭을 만난 경우 
			else if(mp[i][j] > cur){
				//현재 블럭이 l개 이하 연속인경우 
				if(con < l){
					res -= 1;
					break;
				}
				con = 1;
				cur = mp[i][j];
			}
			else if(mp[i][j] < cur){
				int start = mp[i][j];
				int prom = 1;
				for(int k = 0; k < l; k++){
					if(mp[i+k][j] != start){
						prom = 0;
						break;
					}
				}
				if(!prom){
					res -= 1;
					break;
				}
				i += l-1;
				con = 0;
				cur = mp[i][j];
			}
			else
				con += 1;
		}
	}
	
	cout<<res;
	return 0;
}
