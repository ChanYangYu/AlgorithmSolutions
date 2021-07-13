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
    
    deque<int> q;
    
    while(n--){
    	string cmd;
    	
    	cin>>cmd;
    	
    	if(cmd == "push"){
    		int num;
    		
    		cin>>num;
    		q.push_back(num);
		}
		else if(cmd == "pop"){
			if(q.empty())
				cout<<"-1\n";
			else{
				cout<<q.front()<<"\n";
				q.pop_front();
			}
		}
		else if(cmd == "size")
			cout<<q.size()<<"\n";
		else if(cmd == "empty"){
			if(q.empty())
				cout<<"1\n";
			else
				cout<<"0\n";
		}
		else if(cmd == "front"){
			if(q.empty())
				cout<<"-1\n";
			else
				cout<<q.front()<<"\n";
		}
		else if(cmd == "back"){
			if(q.empty())
				cout<<"-1\n";
			else
				cout<<q.back()<<"\n";
		}
	}
    
}
