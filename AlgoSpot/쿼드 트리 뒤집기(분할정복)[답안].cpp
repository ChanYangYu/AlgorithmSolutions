#include <bits/stdc++.h>
using namespace std;

string str;

//분할 정복
string divide_and_conquer(string::iterator& it){
	char head = *it;
	
	it++;	
	//압축이 되어있으면 
	if(head == 'x'){
		string s1,s2,s3,s4;
		
		//왼쪽 상단 압축 string 탐색
		s1 = divide_and_conquer(it);

		//오른쪽 상단 압축 string 탐색		
		s2 = divide_and_conquer(it);
		
		//왼쪽 하단 압축 string 탐색 
		s3 = divide_and_conquer(it);
		
		//오른쪽 하단 압축 string 탐색 
		s4 = divide_and_conquer(it);
		
		// x + (하단 압축 문자열) + (상단 압축 문자열) 
		return string("x") + s3 + s4 + s1 + s2;
	}
	else
		//압축이되지않았으면 현재 start문자열 리턴 
		return string(1,head);
}
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	int n;
	string res;
	
	cin.tie(0);
	cin>>n;
	
	for(int i = 0; i < n; i++){
		cin>>str;
		string::iterator it = str.begin();
		res = divide_and_conquer(it);
		cout<<res<<"\n";
	}
	return 0;
} 
