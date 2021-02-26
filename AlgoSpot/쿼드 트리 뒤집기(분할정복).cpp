#include <bits/stdc++.h>
using namespace std;

string str;

//분할 정복
string divide_and_conquer(int start){
	//윗 부분 
	string top;
	//아랫 부분 
	string bottom;
	
	//압축이 되어있으면 
	if(str[start] == 'x'){
		string s1,s2;
		//'x'다음부터 탐색 
		int len = start + 1;
		
		//왼쪽 상단 압축 string 탐색
		s1 = divide_and_conquer(len);
		//다음 시작위치로 점프 
		len += s1.size();

		//오른쪽 상단 압축 string 탐색		
		s2 = divide_and_conquer(len);
		//다음 시작위치로 점프
		len += s2.size();
		
		//상단의 압축 정보 top에 저장 
		top = s1 + s2;
		
		//왼쪽 하단 압축 string 탐색 
		s1 = divide_and_conquer(len);
		//다음 시작위치로 점프
		len += s1.size();
		
		//오른쪽 하단 압축 string 탐색 
		s2 = divide_and_conquer(len);
		//다음 시작위치로 점프
		len += s2.size();
		
		//하단 압축정보 string에 저장 
		bottom = s1 + s2;
		
		// x + (하단 압축 문자열) + (상단 압축 문자열) 
		return str.substr(start, 1) + bottom + top;
	}
	else
		//압축이되지않았으면 현재 start문자열 리턴 
		return str.substr(start,1);
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
		res = divide_and_conquer(0);
		cout<<res<<"\n";
	}
	return 0;
} 
