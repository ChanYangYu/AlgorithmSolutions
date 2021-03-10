#include <bits/stdc++.h>
using namespace std;
string first, second, target;
int len;
int cache[201][201];

int solve(int f, int s, int t){
	int& ret = cache[f][s];
	
	//방문여부 검토 
	if(ret != -1)
		return ret;
	
	//target에 도달했을 경우 
	if(t == len)
		return ret = 1;
	
	ret = 0;
	//현재 target[t]와 첫번째 문자열[f]가 일치하면 
	if(first[f] == target[t])
		ret = solve(f+1, s, t+1);
	//현재 target[t]와 두번째 문자열[s]가 일치하면 
	if(second[s] == target[t])
		//이전값에 1이 덮어써질 수 있으므로 max를 사용함 
		ret = max(ret, solve(f, s+1, t+1));
	
	return ret;
	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt","rt",stdin);
	int n;
	
	cin>>n;
	
	for(int i = 0; i < n; i++){
		cin>>first>>second>>target;
		memset(cache, -1, sizeof(cache));
		len = first.size() + second.size();
		int res = solve(0, 0, 0);
		
		if(res)
			cout<<"Data set "<<i+1<<": yes\n";
		else
			cout<<"Data set "<<i+1<<": no\n";
	}
	return 0;
}
