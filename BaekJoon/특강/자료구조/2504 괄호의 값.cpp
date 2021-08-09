#include <bits/stdc++.h>
#define ll long long
using namespace std;
string str;
int idx;
ll calc(char pair){
	ll res = 0;
	while(idx < str.size()){
		if(str[idx] == pair){
			idx++;
			if(res == 0)
				return 1;
			else
				return res;
		}
		
		if(str[idx] == '('){
			idx++;
			ll num = calc(')');
			
			if(num == -1)
				return -1;
			else
				res += 2*num;
		}
		else if(str[idx] == '['){
			idx++;
			ll num = calc(']');
			
			if(num == -1)
				return -1;
			else
				res += 3*num;
		}
		else 
			return -1;
	}
	if(pair == ' ')
		return res;
	else
		return -1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>str;
    
    ll res = calc(' ');
    if(res != -1)
		cout<<res;
	else
		cout<<"0";
    
}
