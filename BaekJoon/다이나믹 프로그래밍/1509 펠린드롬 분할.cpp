#include <bits/stdc++.h>
#define ll long long
using namespace std;
string a;
int cache[2501][2501];
vector<int> next_p[2501];

int solve(int left, int right){
	//한 자리 남은 경우 
	if(left == right)
		return 1;
	//모든 자리가 이미 선택된 경우 
	else if(left > right)
		return 0;
	
	int& ret = cache[left][right];
	
	if(ret != -1)
		return ret;
	
	//현재 위치에서 만들 수 있는 펠린드롬 위치를 모두 탐색해본다. 
	for(int i = 0; i < next_p[left].size(); i++){
		//tmp = (펠린드롬 마지막 위치 + 1) ~ (끝 문자열) 의 최솟값 + 1  
		int tmp = solve(next_p[left][i]+1, right) + 1;
		if(ret == -1)
			ret = tmp;
		else
			ret = min(ret, tmp);
	}
	
	return ret;
}
void get_next_pel(int idx){
	int lptr = idx-1;
	int rptr = idx+1;
	int n = a.size();
	
	//한자리인 경우 펠린드롬
	next_p[idx].push_back(idx); 
	
	//현재 위치부터 홀수개 펠린드롬 체크 
	while(lptr >= 0 && rptr <= n-1){
		if(a[lptr] != a[rptr])
			break;
		next_p[lptr--].push_back(rptr++);	
	}
	
	//짝수 개 펠린드롬 체크 
	lptr = idx-1;
	rptr = idx;
		
	while(lptr >= 0 && rptr <= n-1){
		if(a[lptr] != a[rptr])
			break;
		next_p[lptr--].push_back(rptr++);
	}
} 

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	int m;
		
	cin>>a;
	for(int i = 0; i < a.size(); i++)
		get_next_pel(i);
	
	memset(cache, -1, sizeof(cache));
	cout<<solve(0, a.size()-1);
	return 0;
}
