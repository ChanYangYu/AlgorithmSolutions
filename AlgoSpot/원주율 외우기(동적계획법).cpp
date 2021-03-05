#include <bits/stdc++.h>
using namespace std;
string str;
int len;
int cache[10001][3];
int check_difficulty(int pos, int size)
{
	bool diff_1 = true, diff_2 = true, diff_4 = true, diff_5 = true;
	int first = str[pos];
	int second = str[pos+1];
	int diff = first - second;
	int abs_diff = abs(diff);
	
	//숫자가 -1 or 1이 아닌 경우 
	if(abs_diff != 1)
		diff_2 = false;
	
	for(int i = 1; i < size; i++){
		//모두 같지 않은 경우 
		if(diff_1 && str[pos+i] != first)
			diff_1 = false;
		//등차수열이 아닌경우 
		if((str[pos+i-1] - str[pos+i]) != diff){
			diff_2 = false;
			diff_5 = false;
		}
		if(diff_4){
			//i가 홀수인경우 second와 같지않은 경우 
			if(i % 2 == 1 && str[pos+i] != second)
				diff_4 = false;
			//i가 짝수인 경우  first와 같지 않은 경우 
			if(i % 2 == 0 && str[pos+i] != first)
				diff_4 = false;
		}
	}
	
	if(diff_1)
		return 1;
	else if(diff_2)
		return 2;
	else if(diff_4)
		return 4;
	else if(diff_5)
		return 5;
	else
		return 10; 
	
}
int solve(int pos, int size)
{
	/*오답 노트
	- min을 max로 지정하여 정상출력x 
	- if문 로직 연계부분 잘못구현
	- 답이 되지 않는 경우 에러처리 x
	*/ 
	int& ret = cache[pos][size-3];
	
	if(ret != -1)
		return ret;
	
	int diff = check_difficulty(pos, size);
	
	pos += size;
	
	ret = 987654321;
	if(pos == len)
		return ret = diff;
	
	if(pos + 5 <= len)
		ret = min(ret, solve(pos, 5) + diff);
	if(pos + 4 <= len)
		ret = min(ret, solve(pos, 4) + diff);
	if(pos + 3 <= len)
		ret = min(ret, solve(pos, 3) + diff);
	else
		ret = 987654321;
	
	return ret;
	
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt", stdin);
	cin.tie(0);
	int t;
	cin>>t;
	
	for(int k = 0; k < t; k++){
		cin>>str;
		memset(cache, -1, sizeof(cache));
		len = str.size();
		
		int res = solve(0,3);
		res = min(res, solve(0,4));
		res = min(res, solve(0,5));
		cout<<res<<"\n";
	}
	return 0;
}
