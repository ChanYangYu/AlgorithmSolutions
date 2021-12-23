#include <bits/stdc++.h>

/*
	1. 현재 [남은가격][번호]에서 최대로 만들 수 있는 숫자 조합을 구함 
	2. top-down으로 아래 조합들을 모두 탐색한 후 현재 최대가 되는 조합을 ret에 저장
	
	오답노트
	- 00 처리가 안되어있었음
	- str > ret 가 조건이 반대로 되어 있었음 
*/

using namespace std;

string cache[51][11];
int p[11];
int n, m;

string solve(int remain, int number){
	string& ret = cache[remain][number];
	
	// 기저사례 
	if(remain == 0 || number == n)
		return "";
	
	// 이미 [남은가격][번호]로 구할 수 있는 최대 숫자조합을 구한 경우 
	if(ret != "")
		return ret;
	
	string cur = "";
	
	// 현재 숫자를 안구매한 경우 탐색 
	ret = solve(remain, number+1);
	
	// 현재 숫자를 구매할 수 있는 만큼 구매한 경우 탐색 
	while(remain - p[number] >= 0){
		remain -= p[number];
		
		// cur : 현재 구매한 숫자 뭉치 
		cur += to_string(number);
		
		// str : 남은 돈으로 구매할 수 있는 최대 숫자조합 (top-down)
		string str = solve(remain, number+1);
		
		// 만들 수 있는 최대 숫자조합 
		str = cur + str;
		sort(str.begin(), str.end());
		reverse(str.begin(), str.end());
		
		
		// 00 이런식으로 0으로 채워져 있는 경우 예외처리 
		if(str.size() > 1 && str[0] == '0')
			continue;
		
		// 숫자가 더 많은 경우 
		if(str.size() > ret.size())
			ret = str;
		// 조합이 더 큰 경우 
		else if(str.size() == ret.size() && str > ret)
			ret = str;
	}
	
	return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 0; i < n; i++)
    	cin>>p[i];
	
	cin>>m;
	
	cout<<solve(m, 0);
   	return 0;
}
