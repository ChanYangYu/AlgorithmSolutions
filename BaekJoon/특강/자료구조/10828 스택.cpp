#include <bits/stdc++.h>
#define ll long long

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","rt",stdin);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    
    cin>>n;
    
    stack<int> s;
    
    while(n--){
    	string cmd;
    	
    	cin>>cmd;
    	
    	if(cmd == "push"){
    		int num;
    		
    		cin>>num;
    		s.push(num);
		}
		else if(cmd == "pop"){
			if(s.empty())
				cout<<"-1\n";
			else{
				cout<<s.top()<<"\n";
				s.pop();
			}
		}
		else if(cmd == "size")
			cout<<s.size()<<"\n";
		else if(cmd == "empty"){
			if(s.empty())
				cout<<"1\n";
			else
				cout<<"0\n";
		}
		else if(cmd == "top"){
			if(s.empty())
				cout<<"-1\n";
			else
				cout<<s.top()<<"\n";
		}
	}
    
}
