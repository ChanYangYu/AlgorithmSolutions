#include <bits/stdc++.h>
using namespace std;

//컴퓨터의 번호 출력 
int check_computer(int a, int b){
	int res = 1;
	//a 를 b번 곱했을때의 1의자리만 필요 
	for(int i = 0; i < b; i++){
		res *= a;
		res %= 10;
	}
	// a > 1이므로 0인 경우는 10의 배수인 경우 
	if(res == 0)
		res = 10;
	return res;
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	int t;
	
	cin>>t;
	
	//테스트 케이스 검사 
	for(int i = 0; i < t; i++){
		int a, b;
		cin>>a>>b;
		int idx = check_computer(a,b);
		cout<<idx<<endl;
	}
	return 0;
}
