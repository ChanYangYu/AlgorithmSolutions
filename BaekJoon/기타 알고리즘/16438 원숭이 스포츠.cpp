#include <bits/stdc++.h>
using namespace std;
//일주일간 팀배치 
string res[7];

void solve(int depth, int left, int right){
	int mid = (left + right) / 2;
	//한 마리인 경우 
	if(mid == left)
		return;
	else{
		//절반은 B팀 
		for(int i = left; i < mid; i++)
			res[depth][i] = 'B';
		//절반은 A팀 
		for(int i = mid; i < right; i++)
			res[depth][i] = 'A';
		//다음 depth로 이동 
		solve(depth+1, left, mid);
		solve(depth+1, mid, right);
	}
}
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	int n;
	
	cin>>n;
	cin.tie(0);
	int mid = n/2;
	//팀배치 일단 반으로 분류 
	for(int i = 0; i < 7; i++)
		res[i] = string(mid, 'B') + string((n-mid), 'A');
	 
	solve(0,0,n);
	
	//결과 출력 
	for(int i = 0; i < 7; i++)
		cout<<res[i]<<"\n";
	return 0;
} 
