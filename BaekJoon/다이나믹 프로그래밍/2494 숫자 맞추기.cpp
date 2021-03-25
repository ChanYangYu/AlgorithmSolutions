#include <bits/stdc++.h>
using namespace std;
int cache[10001][10][3];
char cur[10001];
char want[10001];
int n;

int solve(int pos, int turn){
	int& ret = cache[pos][turn][0];
	int& next = cache[pos][turn][1];
	int& move = cache[pos][turn][2];
	
	if(ret != -1)
		return ret;
	
	int cur_num = cur[pos] - '0';
	int want_num = want[pos] - '0';
	
	//이동 
	cur_num = (cur_num + turn) % 10;
	
	int left, right;
	
	//left
	if(cur_num > want_num)
		left = (want_num + 10) - cur_num;
	else
		left = want_num - cur_num;
	
	//right
	if(cur_num < want_num)
		right = want_num - (cur_num + 10);
	else
		right = want_num - cur_num;
	
	//마지막인 경우 
	if(pos == n-1){
		if(left < -right){
			move = left;
			return ret = left;
		}
		else{
			move = right;
			return ret = -right;
		}
	} 
	
	//왼쪽으로 이동한 경우
	ret = solve(pos+1, (turn + left) % 10) + left;
	
	//오른쪽으로 이동한 경우 
	int tmp = solve(pos+1, turn) -right;
	
	//오른쪽 이동했을때 경우가 더 작을때 
	if(tmp < ret){
		ret = tmp;
		next = turn;
		move = right;
	}
	
	//왼쪽 이동했을때 경우가 더 작을때 
	else{
		next = (turn + left) % 10;
		move = left;
	}
	
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	
	cin>>n;
	
	for(int i = 0; i < n; i++)
		cin>>cur[i];
	for(int i = 0; i < n; i++)
		cin>>want[i];
	
	memset(cache, -1, sizeof(cache));
	
	int res = solve(0,0);
	
	cout<<res<<"\n";
	int turn = 0;
	for(int i = 0; i < n; i++){
		int move = cache[i][turn][2];
		int next = cache[i][turn][1];
		
		cout<<i+1<<" "<<move<<"\n";
		
		turn = next; 
	}
	
	return 0;
}
