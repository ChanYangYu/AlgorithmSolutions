#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	string str;
	stack<pair<int, char> > s;
	//���ÿ� ����ִ� ���� 
	int count = 0;
	
	cin>>str;
	
	for(int i = 0; i < str.size(); i++){
		if(str[i] == 'A'){
			if(count == 2){
				count++;
				s.push(make_pair(count,'A'));
			}
			//A�ڸ� �̿ܿ� �°�� 
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
				//ž�� �ִ� p�� count������ ���� 
				count = s.top().first;
			}
			else
				s.push(make_pair(count, 'P'));
		}
	}
	
	//���ÿ��� ������ P�ϳ��� ���ƾߵ� 
	if(s.size() == 1 && s.top().second == 'P')
		cout<<"PPAP";
	else
		cout<<"NP";
	return 0;
}
