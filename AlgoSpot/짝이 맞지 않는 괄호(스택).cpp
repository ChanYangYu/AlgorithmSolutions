#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	int t;
	
	cin>>t;
	
	for(int k = 0; k < t; k++){
		string str;
		stack<char> s;
		bool chk = true;
		
		cin>>str;
		for(int i = 0; i < str.size(); i++){
			if(str[i] == '(' || str[i] == '{' || str[i] == '[')
				s.push(str[i]);
			else{
				//순서가 맞지 않은 경우 
				if(s.empty()){
					chk = false;
					break;
				}
				if(str[i] == ')' && s.top() != '('){
					chk = false;
					break;
				}
				else if(str[i] == '}' && s.top() != '{'){
					chk = false;
					break;
				}
				else if(str[i] == ']' && s.top() != '['){
					chk = false;
					break;
				}
				else
					s.pop();
			}
		}
		
		if(s.empty() && chk)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}

	return 0;
}
