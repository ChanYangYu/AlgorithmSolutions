/*
1. 알고리즘 풀이 접근 방법 
- 처음에는 스택을 두개를 생각했다가 string에 폭발문자열에 해당안되는 문자를 넣고
  스택에는 유망한 폭발문자열을 삽입했는데 이렇게 하게되면 문자열의 순서가 맞지 않는 오류가 있다.
  ex) ACBBABCCCD
      BA
	  ACCCCD + BB
- 순서를 위해 스택을 하나만 사용하고 <현재까지 일치개수, 문자> 형식의 스택을 작성하여 풀이

2. 시간복잡도 
- O(N*B)
*/
#include <bits/stdc++.h>
using namespace std;
int main(void){
	ios_base::sync_with_stdio(false);
	string boom;
	string res = "";
	string str;
	int size;
	stack <pair<int, char> > s;
	
	cin>>str;
	cin>>boom;
	size = boom.size();
	
	int count = 0;
	for(int i = 0; i < str.size(); i++){
		//연속적으로 폭발문자열과 일치할때 
		if(boom[count] == str[i]){
			count++;
			if(count == size){
				//size-1개 pop 
				for(int i = 0; i < size-1; i++)
					s.pop();
				//top의 값으로 count 갱신 
				if(!s.empty())
					count = s.top().first;
				else
					count = 0;
			}
			else
				s.push(make_pair(count, str[i]));			
		}
		//폭발 문자열의 첫번째 문자와 같을때 
		else if(boom[0] == str[i]){
			count = 1;
			s.push(make_pair(count, str[i]));
		}
		//아무 관련이 없는 문자열 일때 
		else{
			count = 0;
			s.push(make_pair(count, str[i]));
		}
	}
	
	int st_size = s.size();
	
	if(st_size == 0)
		cout<<"FRULA";
	else{
		string tmp = "";
		for(int i = 0; i < st_size; i++){
			char c = s.top().second;
			tmp += c;
			s.pop();
		}
		for(int i = st_size-1; i >= 0; i--)
			res += tmp[i];
		cout<<res;
	}
    return 0;
}
