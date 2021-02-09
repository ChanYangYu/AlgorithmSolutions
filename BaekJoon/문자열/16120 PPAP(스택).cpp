#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	string str;
	stack<pair<int, char> > s;
	//스택에 들어있는 개수 
	int count = 0;
	
	cin>>str;
	
	for(int i = 0; i < str.size(); i++){
		if(str[i] == 'A'){
			if(count == 2){
				count++;
				s.push(make_pair(count,'A'));
			}
			//A자리 이외에 온경우 
			else{
				cout<<"NP";
				return 0;
			}
		}
		else{ 
			if(count == 0){
				count++;
				s.push(make_pair(count,'P'));
			}
			else if(count == 1){
				count++;
				s.push(make_pair(count,'P'));
			}
			else if(count == 3){
				//A
				s.pop(); 
				//P
				s.pop();
				//탑에 있는 p의 count값으로 갱신 
				count = s.top().first;
			}
			else
				s.push(make_pair(count, 'P'));
		}
	}
	
	//스택에는 무조건 P하나만 남아야됨 
	if(s.size() == 1 && s.top().second == 'P')
		cout<<"PPAP";
	else
		cout<<"NP";
	return 0;
}
